/**
 * \file ActualBasket.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "ActualBasket.h"
#include <string>
using namespace std;

CActualBasket::CActualBasket(const std::wstring& filename) : CTreeImageItem(filename), CBasket()
{
}
/**
* Set the position
* \param x
* \param y
*/
void CActualBasket::SetBasketLocation(int x, int y)
{
	mLocation = Gdiplus::Point(x, y);
}

/**
* Draw the basket
* \param graphics
*/
void CActualBasket::DrawBasket(Gdiplus::Graphics* graphics)
{
	//this->SetBasketLocation(300, 650);
	mBackBasket.DrawImage(graphics, 0, 1, mLocation);
	
	for (std::size_t i = 0; i < mFruit.size(); i++)
	{
		mRandom = CPseudoRandom(i);
		double rotation = mRandom.Random(-45.0, 45.0);
		int dx = mRandom.Random(-30, 30);
		int dy = mRandom.Random(-10, 10);
		mF.DrawImage(graphics, rotation, 0.2, Gdiplus::Point(mLocation.X + dx, mLocation.Y - 70 + dy));

	}
	mFrontBasket.DrawImage(graphics, 0.0, 1.0, mLocation);
	
}

/**
* Add fruit to the basket
* \param fruit
*/
void CActualBasket::AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit)
{
	
	for (auto f : fruit)
	{
		mFruit.push_back(f);
	}
	
}

/**
* Empty basket
*/
void CActualBasket::EmptyBasket()
{
	mFruit.clear();
}