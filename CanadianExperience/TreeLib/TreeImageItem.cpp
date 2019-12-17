/**
 * \file TreeImageItem.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "TreeImageItem.h"
using namespace std;
using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

void CTreeImageItem::LoadImage(const std::wstring& filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

void CTreeImageItem::DrawImage(Gdiplus::Graphics* graphics, double angle, double scale, Gdiplus::Point rootLocation)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)rootLocation.X, (float)rootLocation.Y);
	graphics->RotateTransform((float)(-angle * RtoD));
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2, -(int)mImage->GetHeight(), mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}