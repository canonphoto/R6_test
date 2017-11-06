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

#include <cppuhelper/factory.hxx>
#include <com/sun/star/container/XSet.hpp>

#include "SalAquaFilePicker.hxx"
#include "SalAquaFolderPicker.hxx"

#include "FPServiceInfo.hxx"


using namespace ::com::sun::star::uno;
using namespace ::com::sun::star::container;
using namespace ::com::sun::star::lang;
using namespace ::com::sun::star::registry;
using namespace ::cppu;


static Reference< XInterface > SAL_CALL createFileInstance( const Reference< XMultiServiceFactory >&  )
{
    return Reference< XInterface >( *new SalAquaFilePicker );
}

static Reference< XInterface > SAL_CALL createFolderInstance(
    const Reference< XMultiServiceFactory >& rServiceManager )
{
    return Reference< XInterface >(
        *new SalAquaFolderPicker( rServiceManager ) );
}

extern "C"
{

SAL_DLLPUBLIC_EXPORT void* SAL_CALL fps_aqua_component_getFactory(
    const sal_Char* pImplName, void* pSrvManager, void* /*pRegistryKey*/ )
{
    void* pRet = nullptr;

    if( pSrvManager )
    {
            Reference< XSingleServiceFactory > xFactory;

            if (0 == rtl_str_compare(pImplName, FILE_PICKER_IMPL_NAME))
            {
                Sequence<OUString> aSNS { FILE_PICKER_SERVICE_NAME };

                xFactory = createSingleFactory(
                    static_cast< XMultiServiceFactory* > ( pSrvManager ),
                    OUString::createFromAscii( pImplName ),
                    createFileInstance,
                    aSNS );
            }
            else if (0 == rtl_str_compare(pImplName, FOLDER_PICKER_IMPL_NAME))
            {
                Sequence<OUString> aSNS { FOLDER_PICKER_SERVICE_NAME };

                xFactory = createSingleFactory(
                    static_cast< XMultiServiceFactory* > ( pSrvManager ),
                    OUString::createFromAscii( pImplName ),
                    createFolderInstance,
                    aSNS );
            }

            if ( xFactory.is() )
            {
                xFactory->acquire();
                pRet = xFactory.get();
            }
    }

    return pRet;
}

} // extern "C"

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
