/**
 * \file GrowingStuff.h
 *
 * \author Tom Choi
 *
 *  growing stuff
 */

#pragma once
#include "TreeItem.h"
#include "TreeImageItem.h"
/** growing stuff class
*/
class CGrowingStuff :
	public CTreeItem, public CTreeImageItem
{
public:
	/** \param tree, depth, filename
	*/
	CGrowingStuff(CActualTree* tree, int depth, const std::wstring& filename);
	/** \param graphics, angle, rootLocation
	*/
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point rootLocation);
	/**
	* grow
	*/
	virtual void Grow();
};

