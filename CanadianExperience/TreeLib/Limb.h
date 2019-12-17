/**
 * \file Limb.h
 *
 * \author Tom Choi
 * limb class
 * 
 */

#pragma once
#include "TreeItem.h"
#include <vector>
#include <memory>
#include "FruitVisitor.h"
class PseudoRandom;
/** limb class
*/
class CLimb :
	public CTreeItem
{
public:
	/** \param tree, depth
	*/
	CLimb(CActualTree* tree, int depth);
	/** \param graphics, angle, rootLocation
	*/
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point rootLocation);
	/** grow
	*/
	virtual void Grow();
	/** add child
	*\param child
	*/
	void AddChild(std::shared_ptr<CTreeItem> child);
	
	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitLimb(this); }
	/**
	* \param fruit
	*/
	void EraseChildren(std::shared_ptr<CActualFruit> fruit);
	
private:
	///width
	double mWidth = 0.7;
	///height
	double mHeight = 3;
	///currentlength
	double mCurrentLength = 0;
	///maxlength
	double mMaxLength = 0;
	///mchildren
	std::vector<std::shared_ptr<CTreeItem>> mChildren;
};

