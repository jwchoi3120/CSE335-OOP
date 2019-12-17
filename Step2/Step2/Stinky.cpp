/**
 * \file Stinky.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Stinky.h"
#include "Aquarium.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring StinkyImageName = L"images/stinky.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CStinky::CStinky(CAquarium* aquarium) :
	CItem(aquarium, StinkyImageName)
{
}

void CStinky::SetLocation(double x, double y) 
{
	CItem::SetLocation(x, y);
	mAquarium->Nudge(this);
}