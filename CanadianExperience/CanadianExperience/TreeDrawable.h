/**
 * \file TreeDrawable.h
 *
 * \author Tom Choi
 * tree drawable
 * 
 */

#pragma once
#include "Drawable.h"
#include "Tree.h"
#include <gdiplus.h>
using namespace Gdiplus;
/** treedrawable
*/
class CTreeDrawable :
	public CDrawable
{
public:
	/**
	* constructor
	* \param name the name of the tree that you're creating
	*/
	CTreeDrawable(const std::wstring& name);

	/// Virtual destructor
	virtual ~CTreeDrawable() {}

	/** \brief Default constructor disabled */
	CTreeDrawable() = delete;
	/** \brief Copy constructor disabled */
	CTreeDrawable(const CTreeDrawable&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeDrawable&) = delete;

	/**
	* \param x
	* \param y
	*/
	void SetPosition(int x, int y);

	/**
	* \param graphics
	*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* \param tree
	*/
	void SetTree(std::shared_ptr<CTree> tree) { mTree = tree; }


	/**
	* \param seed
	*/
	void SetSeed(int seed) { mTree->SetSeed(seed); mSeed = seed; }

	/**
	* \return mSeed
	*/
	int GetSeed() { return mSeed; }

	/**
	* \return mTree
	*/
	std::vector<std::shared_ptr<CFruit>> Harvest() { return mTree->Harvest(); }

	/**
	* \param frame
	*/
	virtual void SetKeyFrame(int frame);

	/**
	* \param pos
	* \return false
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* \param timeline
	*/
	void SetTimeline(CTimeline* timeline) { mTimeline = timeline; CDrawable::SetTimeline(timeline); }



private:

	/// The intial frame
	int mInitialFrame = 0;

	/// The timeline
	CTimeline* mTimeline = nullptr;

	///tree
	std::shared_ptr<CTree> mTree;
	///seed
	int mSeed;
	///location
	Point mLocation = Point(0, 0);
};

