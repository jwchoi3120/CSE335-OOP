/**
 * \file CActualFruit.h
 *
 * \author Tom Choi
 *
 * actual fruit class
 */

#pragma once
#include "GrowingStuff.h"
#include "Fruit.h"
#include "FruitVisitor.h"
/** actual fruit class
*/
class CActualFruit :
	public CGrowingStuff, public CFruit
{
public:
	/** constructor
	* \param tree, depth, filename
	*/
	CActualFruit(CActualTree* tree, int depth, const std::wstring& filename);
	/**
	 * Set the position of the fruit in the basket
	 *
	 * This position is relative to the basket, so
	 * it will be added to the basket location passed
	 * to DrawInBasket when we draw it
	 * \param x X position in pixels
	 * \param y Y position in pixels
	 */
	virtual void SetBasketPosition(int x, int y) override;

	/**
	 * Draw the fruit in the basket
	 * \param graphics The graphics object to draw on
	 * \param x X location of the basket
	 * \param y Y location of the basket
	 */
	virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y) override;

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitFruit(this); }
};

