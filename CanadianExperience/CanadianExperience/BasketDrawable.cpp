/**
 * \file BasketDrawable.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "BasketDrawable.h"
CBasketDrawable::CBasketDrawable(const std::wstring& name) : CDrawable(name)
{

}
void CBasketDrawable::Draw(Gdiplus::Graphics* graphics)
{
	mBasket->SetBasketLocation(mLocation.X, mLocation.Y);
	mBasket->DrawBasket(graphics);
}