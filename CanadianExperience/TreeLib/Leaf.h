/**
 * \file Leaf.h
 *
 * \author Tom Choi
 *
 * leaf class
 */

#pragma once
#include "TreeImageItem.h"
#include "TreeItem.h"
#include "GrowingStuff.h"
#include "FruitVisitor.h"
/** leaf class
*/
class CLeaf :
	public CGrowingStuff
{
public:
	/** constructor
	* \param tree, depth, filename
	*/
	CLeaf(CActualTree* tree, int depth, const std::wstring& filename);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitLeaf(this); }
};

