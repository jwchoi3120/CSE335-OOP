/**
 * \file TreeDrawable.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "TreeDrawable.h"
#include "Timeline.h"
#include "TreeSeedDlg.h"
#include "resource.h"

using namespace Gdiplus;

CTreeDrawable::CTreeDrawable(const std::wstring& name) :CDrawable(name)
{

}


void CTreeDrawable::Draw(Gdiplus::Graphics* graphics)
{
	mTree->SetRootLocation(mLocation.X, mLocation.Y);
	if (mTimeline->GetCurrentFrame() < mInitialFrame)
	{
		mTree->SetTreeFrame(0);
	}
	else
	{
		mTree->SetTreeFrame(mTimeline->GetCurrentFrame() - mInitialFrame);
	}

	mTree->DrawTree(graphics);
}

void CTreeDrawable::SetPosition(int x, int y)
{
	mLocation = Point(x, y);
}

void CTreeDrawable::SetKeyFrame(int frame)
{
	mInitialFrame = frame;
	if (mTree != nullptr)
	{
		mTree->SetTreeFrame(frame);
		mSeed = mTree->GetSeed();
	}
}