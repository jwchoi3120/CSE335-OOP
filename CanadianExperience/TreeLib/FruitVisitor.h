/**
 * \file FruitVisitor.h
 *
 * \author Tom Choi
 * fruit visitor
 * 
 */

#pragma once
class CLimb;
class CLeaf;
class CActualFruit;
/** visitor class
*/
class CFruitVisitor
{
public:
	/** \param limb
	*/
	virtual void VisitLimb(CLimb* limb) {}
	/** \param leaf
	*/
	virtual void VisitLeaf(CLeaf* leaf) {}
	/** \param fruit
	*/
	virtual void VisitFruit(CActualFruit* fruit) {}
};

