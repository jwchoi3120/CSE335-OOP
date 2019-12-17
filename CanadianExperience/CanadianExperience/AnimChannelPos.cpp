/**
 * \file AnimChannelPos.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "AnimChannelPos.h"
using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CAnimChannelPos::CAnimChannelPos()
{
}


/**
 * Destructor
 */
CAnimChannelPos::~CAnimChannelPos()
{
}

/**
* Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param point Point for the keyframe.
*/
void CAnimChannelPos::SetKeyframe(Gdiplus::Point point)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the Point
	shared_ptr<KeyframePoint> keyframe =
		make_shared<KeyframePoint>(this, point);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}

/**
* Compute an Point that is an interpolation between two keyframes
*
* This function is called after Use1 and Use2, so we have pointers to
* to valid keyframes of the type KeyframePoint. This function does the
* tweening.
* \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
* interpolate between.
*/
void CAnimChannelPos::Tween(double t)
{

	Point a = mKeyframe1->GetPoint();
	Point b = mKeyframe2->GetPoint();

	Point c(int(a.X + t * (b.X - a.X)), int(a.Y + t * (b.Y - a.Y)));

	mPoint = c;
}