/**
 * \file ActualBasket.h
 *
 * \author Tom Choi
 * actual basket
 * 
 */

#pragma once
#include "Basket.h"
#include "TreeImageItem.h"
#include "ActualTree.h"
#include <gdiplus.h>
#include <string>
using namespace Gdiplus;
/** actual basket class
*/
class CActualBasket :
	public CBasket, public CTreeImageItem
{
public:
	/** constructor
	* \param filename
	*/
	CActualBasket(const std::wstring& filename);
	/**
* Set the position for the basket.
* \param x X location (pixels)
* \param y Y location (pixels)
*/
	virtual void SetBasketLocation(int x, int y);

	/**
	* Draw the basket at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawBasket(Gdiplus::Graphics* graphics);

	/**
	 * Add fruit to the basket
	 * \param fruit Vector of fruit objects
	 */
	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit);

	/**
	 * Empty all fruit from the basket
	 */
	virtual void EmptyBasket();
private:
	///location
	Gdiplus::Point mLocation = Point(300, 650);
	///front
	CTreeImageItem mFrontBasket = CTreeImageItem(L"images/basket-front.png");
	
	///back
	CTreeImageItem mBackBasket = CTreeImageItem(L"images/basket.png");
	///fruits
	std::vector < std::shared_ptr<CFruit>> mFruit;
	///apple picture
	CTreeImageItem mF = CTreeImageItem(L"images/apple.png");
	///random
	CPseudoRandom mRandom = CPseudoRandom(134);

	/// The image for the leaf drawable
	Gdiplus::Bitmap* mFruitImage = (Gdiplus::Bitmap::FromFile(L"images/apple.png"));

};

