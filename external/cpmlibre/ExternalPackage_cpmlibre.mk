# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_ExternalPackage_ExternalPackage,cpmlibre,CPMLIBRE))

$(eval $(call gb_ExternalPackage_add_unpacked_files_with_dir,cpmlibre,share/extensions/CPMLIBRE,\
    description_en-US.txt \
	description.xml \
	description_zh-TW.txt \
	genicons.sh \
	icons/lc04.png \
	icons/lc13.png \
	icons/lc35.png \
	icons/lc03.png \
	icons/lc26.png \
	icons/lc22.png \
	icons/lc24.png \
	icons/lc30.png \
	icons/lc00.png \
	icons/lc09.png \
	icons/lc31.png \
	icons/lc19.png \
	icons/lc28.png \
	icons/lc01.png \
	icons/lc12.png \
	icons/lc10.png \
	icons/lc02.png \
	icons/lc36.png \
	icons/lc21.png \
	icons/lc32.png \
	icons/lc16.png \
	icons/lc07.png \
	icons/lc14.png \
	icons/lc08.png \
	icons/lc11.png \
	icons/lc33.png \
	icons/lc29.png \
	icons/lc17.png \
	icons/lc18.png \
	icons/lc34.png \
	icons/lc27.png \
	icons/lc15.png \
	icons/lc25.png \
	icons/lc23.png \
	icons/lc06.png \
	icons/lc05.png \
	icons/lc20.png \
	iconsb/lc04.png \
	iconsb/lc13.png \
	iconsb/lc35.png \
	iconsb/lc03.png \
	iconsb/lc26.png \
	iconsb/lc22.png \
	iconsb/lc24.png \
	iconsb/lc30.png \
	iconsb/lc00.png \
	iconsb/lc09.png \
	iconsb/lc31.png \
	iconsb/lc19.png \
	iconsb/lc28.png \
	iconsb/lc01.png \
	iconsb/lc12.png \
	iconsb/lc10.png \
	iconsb/lc02.png \
	iconsb/lc36.png \
	iconsb/lc21.png \
	iconsb/lc32.png \
	iconsb/lc16.png \
	iconsb/lc07.png \
	iconsb/lc14.png \
	iconsb/lc08.png \
	iconsb/lc11.png \
	iconsb/lc33.png \
	iconsb/lc29.png \
	iconsb/lc17.png \
	iconsb/lc18.png \
	iconsb/lc34.png \
	iconsb/lc27.png \
	iconsb/lc15.png \
	iconsb/lc25.png \
	iconsb/lc23.png \
	iconsb/lc06.png \
	iconsb/lc05.png \
	iconsb/lc20.png \
	labels.txt \
	META-INF/manifest.xml \
	registry/Addons.xcu \
	registry/CalcWindowState.xcu \
	registry/ImpressWindowState.xcu \
	registry/DrawWindowState.xcu \
	registry/Addons3.4.xcu \
	registry/WriterWindowState.xcu \
	ZHTWPunctuation/dialog.xlb \
	ZHTWPunctuation/script.xlb \
	ZHTWPunctuation/SymbolTools.xba  \
))

# vim: set noet sw=4 ts=4:
