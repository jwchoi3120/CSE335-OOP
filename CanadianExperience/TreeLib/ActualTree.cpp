/**
 * \file ActualTree.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "ActualTree.h"
#include "Limb.h"
#include <memory>
using namespace std;
CActualTree::CActualTree()
{
	mRoot = make_shared<CLimb>(this, mDepth);
	mRoot->SetTree(this);
}

void CActualTree::DrawTree(Gdiplus::Graphics* graphics)
{
	//this->SetRootLocation(600, 700);
	mRoot->Draw(graphics, 0, mPos);
}
/**
 * Set the current tree frame
 * \param frame Frame number
 */
void CActualTree::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow();
	}
}

void CActualTree::Reset()
{
	mRandom = CPseudoRandom(mSeed);
	mCurrentFrame = 0;
	mRoot = std::make_shared<CLimb>(this, mDepth);
}

std::vector<std::shared_ptr<CFruit>> CActualTree::Harvest()
{
	std::vector<std::shared_ptr<CFruit>> fruit;
	
	for (auto f : mFruits)
	{
		fruit.push_back(f);
		f->GetParent()->EraseChildren(f);
	}
	mFruits.clear();
	return fruit;
}
