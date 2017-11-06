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

package mod._sc;

import java.io.PrintWriter;

import lib.TestCase;
import lib.TestEnvironment;
import lib.TestParameters;

import com.sun.star.uno.XInterface;

/**
* Test for object which is represented by service
* <code>com.sun.star.sheet.GlobalSheetSettings</code>. <p>
* Object implements the following interfaces :
* <ul>
*  <li> <code>com::sun::star::sheet::GlobalSheetSettings</code></li>
*  <li> <code>com::sun::star::beans::XPropertySet</code></li>
* </ul>
* @see com.sun.star.sheet.GlobalSheetSettings
* @see com.sun.star.beans.XPropertySet
* @see ifc.sheet._GlobalSheetSettings
* @see ifc.beans._XPropertySet
*/
public class ScSpreadsheetSettings extends TestCase {

    /**
    * Creating a TestEnvironment for the interfaces to be tested.
    * Creates an instance of the service
    * <code>com.sun.star.sheet.GlobalSheetSettings</code>.
    */
    @Override
    public TestEnvironment createTestEnvironment(
        TestParameters tParam, PrintWriter log) throws Exception {

        XInterface oObj = null;

        // creation of testobject here
        // first we write what we are intend to do to log file
        log.println( "creating a test environment" );

        // create testobject here
        oObj = (XInterface)tParam.getMSF().
            createInstance("com.sun.star.sheet.GlobalSheetSettings");

        TestEnvironment tEnv = new TestEnvironment(oObj);

        return tEnv;
    } // finish method getTestEnvironment

}    // finish class ScSpreadsheetSettings

