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

#ifndef INCLUDED_SD_SOURCE_UI_INC_DRAWSUBCONTROLLER_HXX
#define INCLUDED_SD_SOURCE_UI_INC_DRAWSUBCONTROLLER_HXX

#include <com/sun/star/drawing/XDrawSubController.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <cppuhelper/compbase.hxx>

namespace sd {

    class DrawSubControllerInterfaceBase : public ::cppu::WeakComponentImplHelper<
                    css::drawing::XDrawSubController,
                    css::lang::XServiceInfo >
    {
    public:
        DrawSubControllerInterfaceBase( ::osl::Mutex& aMutex )
            :  ::cppu::WeakComponentImplHelper<
                    css::drawing::XDrawSubController,
                    css::lang::XServiceInfo >( aMutex ) {}

        // XServiceInfo
        virtual OUString SAL_CALL getImplementationName(  ) throw (css::uno::RuntimeException, std::exception) override = 0;
        virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) throw (css::uno::RuntimeException, std::exception) override = 0;
        virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames(  ) throw (css::uno::RuntimeException, std::exception) override = 0;
    };

}

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
