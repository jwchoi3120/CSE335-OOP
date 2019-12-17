/**
 * \file ActualTree.h
 *
 * \author Tom Choi
 * actual tree class
 * 
 */

#pragma once
#include "Tree.h"
#include "PseudoRandom.h"
#include "CActualFruit.h"
#include <memory>
class CLimb;
class CTreeItem;
/** actual tree class
*/
class CActualTree :
	public CTree
{
public:
	/** \brief Copy constructor disabled */
	CActualTree(const CActualTree&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActualTree&) = delete;
	/** constructor*/
	CActualTree();
	/** destructor */
	virtual ~CActualTree() {};
	/** \return mRandom
	*/
	CPseudoRandom* GetRandom() { return &mRandom; }

	/**
	* Set the position for the root of the tree
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetRootLocation(int x, int y) { mPos = Gdiplus::Point(x, y); };

	/**
	* Draw the tree at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawTree(Gdiplus::Graphics* graphics);

	/**
	* Set the current tree frame
	* \param frame Frame number
	*/
	virtual void SetTreeFrame(int frame);

	/**
	* Set  the wind speed
	* \param speed Wind speed in miles per hour
	*/
	virtual void SetWindSpeed(double speed) { mWindSpeed = speed * 0.002; }

	/**
	* Set the tree seed
	* \param seed An integer number. Each number makes a different tree
	*/
	virtual void SetSeed(int seed) override { mSeed = seed; }

	/**
	 * Get the current tree seed
	 * \return Tree seed integer
	 */
	virtual int GetSeed() { return mSeed; }
	
	/** \return mCurrentFrame
	*/
	int GetFrame() { return mCurrentFrame; }
	/** \return mFrameRate
	*/
	int GetFrameRate() { return mFrameRate; }
	/** reset
	*/
	void Reset();
	/** \return mDepth
	*/
	int GetDepth() { return mDepth; }
	/** \param fruit
	*/
	void AddFruit(std::shared_ptr<CActualFruit> fruit) { mFruits.push_back(fruit); }
	/**
	 * Harvest all of the fruit
	 * \return Vector of objects of type CFruit
	 */
	virtual std::vector<std::shared_ptr<CFruit>> Harvest();
	/**
	* \return mWindSpeed
	*/
	double GetWindSpeed() { return mWindSpeed; }
private:
	///current frame
	int mCurrentFrame = 0;
	///frame rate
	int mFrameRate = 0;
	///mseed
	int mSeed = 3602;
	///random
	CPseudoRandom mRandom = CPseudoRandom(mSeed);
	///windspeed
	double mWindSpeed = 0;
	///height
	int height;
	///depth
	int mDepth = 0;
	///root
	std::shared_ptr<CTreeItem> mRoot;
	///position
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	///fruits
	std::vector<std::shared_ptr<CActualFruit>> mFruits;
};

