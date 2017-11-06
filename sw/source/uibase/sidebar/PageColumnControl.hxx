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
#ifndef INCLUDED_SW_SOURCE_UIBASE_SIDEBAR_PAGECOLUMNCONTROL_HXX
#define INCLUDED_SW_SOURCE_UIBASE_SIDEBAR_PAGECOLUMNCONTROL_HXX

#include <svx/sidebar/PopupControl.hxx>

#include <vcl/image.hxx>
#include <vcl/button.hxx>

#include <vector>

namespace svx { namespace sidebar {
    class ValueSetWithTextControl;
} }
class ValueSet;

namespace sw { namespace sidebar {

class PagePropertyPanel;

class PageColumnControl
    : public svx::sidebar::PopupControl
{
public:
    PageColumnControl(
        vcl::Window* pParent,
        PagePropertyPanel& rPanel,
        const sal_uInt16 nColumnType,
        const bool bLandscape );

    virtual ~PageColumnControl();
    virtual void dispose() override;

private:
    VclPtr< svx::sidebar::ValueSetWithTextControl> mpColumnValueSet;
    VclPtr<PushButton> maMoreButton;

    sal_uInt16 mnColumnType;

    PagePropertyPanel& mrPagePropPanel;

    DECL_LINK_TYPED(ImplColumnHdl, ValueSet*, void);
    DECL_LINK_TYPED(MoreButtonClickHdl_Impl, Button*, void);
};

} } // end of namespace sw::sidebar

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
