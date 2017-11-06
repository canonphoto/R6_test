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
package mod._forms;

import java.io.PrintWriter;

import lib.TestParameters;



/**
* Test for object which is represented by service
* <code>com.sun.star.form.component.CheckBox</code>. <p>
* Object implements the following interfaces :
* <ul>
*  <li> <code>com::sun::star::beans::XFastPropertySet</code></li>
*  <li> <code>com::sun::star::io::XPersistObject</code></li>
*  <li> <code>com::sun::star::form::XReset</code></li>
*  <li> <code>com::sun::star::form::FormComponent</code></li>
*  <li> <code>com::sun::star::form::component::CheckBox</code></li>
*  <li> <code>com::sun::star::beans::XMultiPropertySet</code></li>
*  <li> <code>com::sun::star::form::DataAwareControlModel</code></li>
*  <li> <code>com::sun::star::form::XUpdateBroadcaster</code></li>
*  <li> <code>com::sun::star::beans::XPropertyState</code></li>
*  <li> <code>com::sun::star::form::FormControlModel</code></li>
*  <li> <code>com::sun::star::awt::UnoControlCheckBoxModel</code></li>
*  <li> <code>com::sun::star::container::XNamed</code></li>
*  <li> <code>com::sun::star::form::XBoundComponent</code></li>
*  <li> <code>com::sun::star::lang::XComponent</code></li>
*  <li> <code>com::sun::star::lang::XEventListener</code></li>
*  <li> <code>com::sun::star::beans::XPropertyAccess</code></li>
*  <li> <code>com::sun::star::beans::XPropertyContainer</code></li>
*  <li> <code>com::sun::star::beans::XPropertySet</code></li>
*  <li> <code>com::sun::star::form::XLoadListener</code></li>
*  <li> <code>com::sun::star::container::XChild</code></li>
* </ul>
* This object test <b> is NOT </b> designed to be run in several
* threads concurrently.
*
* @see com.sun.star.beans.XFastPropertySet
* @see com.sun.star.io.XPersistObject
* @see com.sun.star.form.XReset
* @see com.sun.star.form.FormComponent
* @see com.sun.star.form.component.CheckBox
* @see com.sun.star.beans.XMultiPropertySet
* @see com.sun.star.form.DataAwareControlModel
* @see com.sun.star.form.XUpdateBroadcaster
* @see com.sun.star.beans.XPropertyState
* @see com.sun.star.form
* @see com.sun.star.awt.UnoControlCheckBoxModel
* @see com.sun.star.container.XNamed
* @see com.sun.star.form.XBoundComponent
* @see com.sun.star.lang.XComponent
* @see com.sun.star.lang.XEventListener
* @see com.sun.star.beans.XPropertyAccess
* @see com.sun.star.beans.XPropertyContainer
* @see com.sun.star.beans.XPropertySet
* @see com.sun.star.form.XLoadListener
* @see com.sun.star.container.XChild
* @see ifc.beans._XFastPropertySet
* @see ifc.io._XPersistObject
* @see ifc.form._XReset
* @see ifc.form._FormComponent
* @see ifc.form.component._CheckBox
* @see ifc.beans._XMultiPropertySet
* @see ifc.form._DataAwareControlModel
* @see ifc.form._XUpdateBroadcaster
* @see ifc.beans._XPropertyState
* @see ifc.form._FormControlModel
* @see ifc.awt._UnoControlCheckBoxModel
* @see ifc.container._XNamed
* @see ifc.form._XBoundComponent
* @see ifc.lang._XComponent
* @see ifc.lang._XEventListener
* @see ifc.beans._XPropertySet
* @see ifc.form._XLoadListener
* @see ifc.container._XChild
*/
public class OCheckBoxModel extends GenericModelTest {

    /**
     * Set some member variable of the super class <CODE>GenericModelTest</CODE>:
     * <pre>
     *    super.m_kindOfControl="CheckBox";
     *    super.m_ObjectName = "stardiv.one.form.component.CheckBox";
     *    super.m_LCShape_Type = "FixedText";
     * </pre>
     * Then <CODE>super.initialize()</CODE> was called.
     * @param tParam the test parameter
     * @param log the log writer
     */
    @Override
    protected void initialize(TestParameters tParam, PrintWriter log) throws Exception {

        super.initialize(tParam, log);

        super.m_kindOfControl=  "CheckBox";

        super.m_ObjectName = "stardiv.one.form.component.CheckBox";

        super.m_LCShape_Type = "FixedText";

    }

}    // finish class OCheckBoxModel

