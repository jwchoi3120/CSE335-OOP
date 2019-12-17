/**
 * \file TreeItem.h
 *
 * \author Tom Choi
 *
 * tree item class
 */


#pragma once

#include <gdiplus.h>
class CActualTree;
class CFruitVisitor;
class CLimb;
/** treeitem class
*/
class CTreeItem
{
public:
	/** constructor
	* \param tree, depth
	*/
	CTreeItem(CActualTree* tree, int depth) : mTree(tree), mDepth(depth) {};
	/** \param graphics, angle, rootLocation
	*/
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point rootLocation) = 0;
	///grow
	virtual void Grow() = 0;
	/** \param tree
	*/
	void SetTree(CActualTree* tree) { mTree = tree; }
	/** \return mScale
	*/
	double GetScale() { return mScale; }
	/** \return mDepth
	*/
	int GetDepth() { return mDepth; }
	/** \param depth
	*/
	void SetDepth(int depth) { mDepth = depth; }
	/** \return mTree
	*/
	virtual CActualTree* GetTree() { return mTree; }
	/** \param parent
	*/
	void SetParent(CLimb* parent) { mParent = parent; }
	/** \return mParent
	*/
	CLimb* GetParent() { return mParent; }
	/**
	* \param scale
	*/
	void SetScale(float scale) { mScale = scale; }

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) = 0;

	/** \param angle
	*/
	void SetAngle(double angle) { mAngle = angle; }
	/** \return mAngle
	*/
	double GetAngle() { return mAngle; }
private:
	///location
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	///angle
	double mAngle = 0;
	///scale
	double mScale = 0.035;
	///maturity
	int mMaturity = 0;
	///depth
	int mDepth = 1;
	///parent
	CLimb* mParent = nullptr;
	///mTree
	CActualTree* mTree = nullptr;
};

