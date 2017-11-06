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
#ifndef INCLUDED_EDITENG_SIZEITEM_HXX
#define INCLUDED_EDITENG_SIZEITEM_HXX

#include <tools/gen.hxx>
#include <svl/poolitem.hxx>
#include <editeng/editengdllapi.h>

// class SvxSizeItem -----------------------------------------------------

/*  [Description]

    This item describes a two-dimensional size.
*/

class EDITENG_DLLPUBLIC SvxSizeItem : public SfxPoolItem
{

    Size aSize;

public:
    static SfxPoolItem* CreateDefault();

    explicit SvxSizeItem( const sal_uInt16 nId );
    SvxSizeItem( const sal_uInt16 nId, const Size& rSize);

    inline SvxSizeItem& operator=( const SvxSizeItem &rCpy );

    // "pure virtual Methods" from SfxPoolItem
    virtual bool            operator==( const SfxPoolItem& ) const override;
    virtual bool            QueryValue( css::uno::Any& rVal, sal_uInt8 nMemberId = 0 ) const override;
    virtual bool            PutValue( const css::uno::Any& rVal, sal_uInt8 nMemberId ) override;

    virtual bool GetPresentation( SfxItemPresentation ePres,
                                    SfxMapUnit eCoreMetric,
                                    SfxMapUnit ePresMetric,
                                    OUString &rText, const IntlWrapper * = nullptr ) const override;

    virtual SfxPoolItem*     Clone( SfxItemPool *pPool = nullptr ) const override;
    virtual SfxPoolItem*     Create(SvStream &, sal_uInt16) const override;
    virtual SvStream&        Store(SvStream &, sal_uInt16 nItemVersion ) const override;
    virtual void             ScaleMetrics( long nMult, long nDiv ) override;
    virtual bool             HasMetrics() const override;

    const Size& GetSize() const { return aSize; }
    void        SetSize(const Size& rSize) { aSize = rSize; }
};

inline SvxSizeItem& SvxSizeItem::operator=( const SvxSizeItem &rCpy )
{
    aSize = rCpy.aSize;
    return *this;
}

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
