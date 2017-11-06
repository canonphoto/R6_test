/* -*- Mode: Java; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*************************************************************************
 *
 *  The Contents of this file are made available subject to the terms of
 *  the BSD license.
 *
 *  Copyright 2000, 2010 Oracle and/or its affiliates.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Sun Microsystems, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *************************************************************************/

import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XComponentContext;
import com.sun.star.lang.XMultiComponentFactory;
import com.sun.star.frame.XDesktop;

public class TerminationTest {

    private static boolean atWork = false;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        XComponentContext xRemoteContext = null;
        XMultiComponentFactory xRemoteServiceManager = null;
        XDesktop xDesktop = null;

        try {
            // get the remote office context. If necessary a new office
            // process is started
            xRemoteContext = com.sun.star.comp.helper.Bootstrap.bootstrap();
            System.out.println("Connected to a running office ...");
            xRemoteServiceManager = xRemoteContext.getServiceManager();

            Object desktop = xRemoteServiceManager.createInstanceWithContext(
                "com.sun.star.frame.Desktop", xRemoteContext);
            xDesktop = UnoRuntime.queryInterface(XDesktop.class, desktop);

            TerminateListener terminateListener = new TerminateListener();
            xDesktop.addTerminateListener(terminateListener);

            atWork = true;
            // try to terminate while we are at work
            boolean terminated = xDesktop.terminate();
            System.out.println("The Office " +
                (terminated ?
                 "has been terminated" :
                 "is still running, we are at work"));

            // no longer at work
            atWork = false;
            // once more: try to terminate
            terminated = xDesktop.terminate();
            System.out.println("The Office " +
                (terminated ?
                    "has been terminated" :
                    "is still running. Someone else prevents termination, " +
                    "e.g. the quickstarter"));
        }
        catch (java.lang.Exception e){
            e.printStackTrace();
        }
        finally {
            System.exit(0);
        }


    }
    public static boolean isAtWork() {
        return atWork;
    }

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
