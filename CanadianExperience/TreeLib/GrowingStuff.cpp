/**
 * \file GrowingStuff.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "GrowingStuff.h"
///growth rate
double GrowthRate = 0.45;

CGrowingStuff::CGrowingStuff(CActualTree* tree, int depth, const std::wstring& filename) : CTreeItem(tree, depth), CTreeImageItem(filename)
{

}

void CGrowingStuff::Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point rootLocation)
{
	DrawImage(graphics, angle, GetScale(), rootLocation);
}

void CGrowingStuff::Grow()
{
	double delta = 1 / 30.0;
	double growRate = pow((1.0 + GrowthRate), delta);
	SetScale(GetScale() * growRate);
}
