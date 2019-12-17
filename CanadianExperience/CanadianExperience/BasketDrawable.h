/**
 * \file BasketDrawable.h
 *
 * \author Tom Choi
 * basket adapter class
 * 
 */

#pragma once
#include "Drawable.h"
#include "Basket.h"
#include "Fruit.h"
/** class basket adapter
*/
class CBasketDrawable :
	public CDrawable
{
public:
	/** \param name
	*/
	CBasketDrawable(const std::wstring& name);
	virtual ~CBasketDrawable() {}

	/**
	* \param x
	* \param y
	*/
	void SetPosition(int x, int y) {}

	/**
	* \param graphics
	*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;
	
	/**
	* \param frame
	*/
	void SetKeyFrame(int frame) { mStartFrame = frame; }


	/**
	* \param pos
	* \return bool
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* \param basket
	*/
	void SetBasket(std::shared_ptr<CBasket> basket) { mBasket = basket; }

	/**
	* \param fruit
	*/
	void AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit) { mBasket->AddToBasket(fruit); }

private:
	///location
	Gdiplus::Point mLocation = Gdiplus::Point(800, 500);
	/// startframe
	int mStartFrame;

	/// basket
	std::shared_ptr<CBasket> mBasket;
};

