/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include <sfx2/sidebar/SidebarToolBox.hxx>
#include <sfx2/sidebar/ControllerFactory.hxx>
#include <sfx2/sidebar/Theme.hxx>
#include <sfx2/sidebar/Tools.hxx>

#include <vcl/builderfactory.hxx>
#include <vcl/gradient.hxx>
#include <vcl/settings.hxx>
#include <toolkit/helper/vclunohelper.hxx>
#include <svtools/miscopt.hxx>
#include <com/sun/star/frame/XSubToolbarController.hpp>

using namespace css;
using namespace css::uno;

namespace {
    void lcl_RTLizeCommandURL( OUString& rCommandURL )
    {
        if (rCommandURL == ".uno:ParaLeftToRight")
            rCommandURL = ".uno:ParaRightToLeft";
        else if (rCommandURL == ".uno:ParaRightToLeft")
            rCommandURL = ".uno:ParaLeftToRight";
        else if (rCommandURL == ".uno:LeftPara")
            rCommandURL = ".uno:RightPara";
        else if (rCommandURL == ".uno:RightPara")
            rCommandURL = ".uno:LeftPara";
        else if (rCommandURL == ".uno:AlignLeft")
            rCommandURL = ".uno:AlignRight";
        else if (rCommandURL == ".uno:AlignRight")
            rCommandURL = ".uno:AlignLeft";
    }
}

namespace sfx2 { namespace sidebar {

SidebarToolBox::SidebarToolBox (vcl::Window* pParentWindow)
    : ToolBox(pParentWindow, 0),
      maControllers(),
      mbAreHandlersRegistered(false)
{
    SetBackground(Wallpaper());
    SetPaintTransparent(true);
    SetToolboxButtonSize( TOOLBOX_BUTTONSIZE_SMALL );

#ifdef DEBUG
    SetText(OUString("SidebarToolBox"));
#endif
}

VCL_BUILDER_FACTORY(SidebarToolBox)

SidebarToolBox::~SidebarToolBox()
{
    disposeOnce();
}

void SidebarToolBox::dispose()
{
    ControllerContainer aControllers;
    aControllers.swap(maControllers);
    for (ControllerContainer::iterator iController(aControllers.begin()), iEnd(aControllers.end());
         iController!=iEnd;
         ++iController)
    {
        Reference<lang::XComponent> xComponent(iController->second, UNO_QUERY);
        if (xComponent.is())
            xComponent->dispose();
    }

    if (mbAreHandlersRegistered)
    {
        SetDropdownClickHdl(Link<ToolBox *, void>());
        SetClickHdl(Link<ToolBox *, void>());
        SetDoubleClickHdl(Link<ToolBox *, void>());
        SetSelectHdl(Link<ToolBox *, void>());
        SetActivateHdl(Link<ToolBox *, void>());
        SetDeactivateHdl(Link<ToolBox *, void>());
        mbAreHandlersRegistered = false;
    }

    ToolBox::dispose();
}

void SidebarToolBox::InsertItem(const OUString& rCommand,
        const css::uno::Reference<css::frame::XFrame>& rFrame,
        ToolBoxItemBits nBits, const Size& rRequestedSize, sal_uInt16 nPos)
{
    OUString aCommand( rCommand );

    if( AllSettings::GetLayoutRTL() )
    {
        lcl_RTLizeCommandURL( aCommand );
    }

    ToolBox::InsertItem(aCommand, rFrame, nBits, rRequestedSize, nPos);

    CreateController(GetItemId(aCommand), rFrame, std::max(rRequestedSize.Width(), 0L));
    RegisterHandlers();
}

bool SidebarToolBox::Notify (NotifyEvent& rEvent)
{
    if (rEvent.GetType() == MouseNotifyEvent::KEYINPUT)
    {
        if (rEvent.GetKeyEvent()->GetKeyCode().GetCode() == KEY_TAB)
        {
            // Special handling for transferring handling of KEY_TAB
            // that becomes necessary because of our parent that is
            // not the dialog but a background control.
            return DockingWindow::Notify(rEvent);
        }
    }
    return ToolBox::Notify(rEvent);
}

void SidebarToolBox::CreateController (
    const sal_uInt16 nItemId,
    const css::uno::Reference<css::frame::XFrame>& rxFrame,
    const sal_Int32 nItemWidth)
{
    const OUString sCommandName (GetItemCommand(nItemId));

    uno::Reference<frame::XToolbarController> xController(sfx2::sidebar::ControllerFactory::CreateToolBoxController(
            this, nItemId, sCommandName, rxFrame, rxFrame->getController(),
            VCLUnoHelper::GetInterface(this), nItemWidth));

    if (xController.is())
        maControllers.insert(std::make_pair(nItemId, xController));
}

Reference<frame::XToolbarController> SidebarToolBox::GetControllerForItemId (const sal_uInt16 nItemId) const
{
    ControllerContainer::const_iterator iController (maControllers.find(nItemId));
    if (iController != maControllers.end())
        return iController->second;

    return Reference<frame::XToolbarController>();
}

void SidebarToolBox::SetController(const sal_uInt16 nItemId,
                                   const css::uno::Reference<css::frame::XToolbarController>& rxController)
{
    ControllerContainer::iterator iController (maControllers.find(nItemId));
    if (iController != maControllers.end())
    {
        Reference<lang::XComponent> xComponent(rxController, UNO_QUERY);
        if (xComponent.is())
            xComponent->dispose();

        iController->second = rxController;
    }
    else
    {
        maControllers[nItemId] = rxController;
    }

    if (rxController.is())
        RegisterHandlers();
}

css::uno::Reference<css::frame::XToolbarController> SidebarToolBox::GetFirstController()
{
    if (maControllers.empty())
        return css::uno::Reference<css::frame::XToolbarController>();

    return maControllers.begin()->second;
}

void SidebarToolBox::RegisterHandlers()
{
    if ( ! mbAreHandlersRegistered)
    {
        mbAreHandlersRegistered = true;
        SetDropdownClickHdl(LINK(this, SidebarToolBox, DropDownClickHandler));
        SetClickHdl(LINK(this, SidebarToolBox, ClickHandler));
        SetDoubleClickHdl(LINK(this, SidebarToolBox, DoubleClickHandler));
        SetSelectHdl(LINK(this, SidebarToolBox, SelectHandler));
    }
}

IMPL_LINK_TYPED(SidebarToolBox, DropDownClickHandler, ToolBox*, pToolBox, void)
{
    if (pToolBox != nullptr)
    {
        Reference<frame::XToolbarController> xController (GetControllerForItemId(pToolBox->GetCurItemId()));
        if (xController.is())
        {
            Reference<awt::XWindow> xWindow = xController->createPopupWindow();
            if (xWindow.is() )
                xWindow->setFocus();
        }
    }
}

IMPL_LINK_TYPED(SidebarToolBox, ClickHandler, ToolBox*, pToolBox, void)
{
    if (pToolBox == nullptr)
        return;

    Reference<frame::XToolbarController> xController (GetControllerForItemId(pToolBox->GetCurItemId()));
    if (xController.is())
        xController->click();
}

IMPL_LINK_TYPED(SidebarToolBox, DoubleClickHandler, ToolBox*, pToolBox, void)
{
    if (pToolBox == nullptr)
        return;

    Reference<frame::XToolbarController> xController (GetControllerForItemId(pToolBox->GetCurItemId()));
    if (xController.is())
        xController->doubleClick();
}

IMPL_LINK_TYPED(SidebarToolBox, SelectHandler, ToolBox*, pToolBox, void)
{
    if (pToolBox == nullptr)
        return;

    Reference<frame::XToolbarController> xController (GetControllerForItemId(pToolBox->GetCurItemId()));
    if (xController.is())
        xController->execute((sal_Int16)pToolBox->GetModifier());
}

} } // end of namespace sfx2::sidebar

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
