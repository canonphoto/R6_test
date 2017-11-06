# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_CppunitTest_CppunitTest,svgio))

$(eval $(call gb_CppunitTest_set_componentfile,svgio,svgio/svgio))

$(eval $(call gb_CppunitTest_set_include,svgio,\
    $$(INCLUDE) \
    -I$(SRCDIR)/svgio/inc \
))

$(eval $(call gb_CppunitTest_use_externals,svgio,\
    boost_headers \
    libxml2 \
))

$(eval $(call gb_CppunitTest_use_api,svgio,\
    offapi \
    udkapi \
))

$(eval $(call gb_CppunitTest_use_library_objects,svgio,\
    svgio \
))

$(eval $(call gb_CppunitTest_use_libraries,svgio,\
    basegfx \
    drawinglayer \
    cppu \
    cppuhelper \
    comphelper \
    sal \
    sax \
    svt \
    test \
    unotest \
    tl \
    vcl \
	$(gb_UWINAPI) \
))

$(eval $(call gb_CppunitTest_add_exception_objects,svgio,\
    svgio/qa/cppunit/SvgImportTest \
))

$(eval $(call gb_CppunitTest_use_ure,svgio))
$(eval $(call gb_CppunitTest_use_vcl,svgio))

$(eval $(call gb_CppunitTest_use_components,svgio,\
    configmgr/source/configmgr \
    dtrans/util/mcnttype \
    framework/util/fwk \
    i18npool/util/i18npool \
    package/source/xstor/xstor \
    package/util/package2 \
    toolkit/util/tk \
    sfx2/util/sfx \
    ucb/source/core/ucb1 \
    ucb/source/ucp/file/ucpfile1 \
    unotools/util/utl \
    sax/source/expatwrap/expwrap \
))

$(eval $(call gb_CppunitTest_use_configuration,svgio))

# vim: set noet sw=4 ts=4:
