/**
 * \file CActualFruit.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "CActualFruit.h"
CActualFruit::CActualFruit(CActualTree* tree, int depth, const std::wstring& filename) : CGrowingStuff(tree, depth, filename), CFruit()
{

}

void CActualFruit::SetBasketPosition(int x, int y)
{

}

void CActualFruit::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	DrawImage(graphics, 0, 1, Gdiplus::Point(x, y));
}