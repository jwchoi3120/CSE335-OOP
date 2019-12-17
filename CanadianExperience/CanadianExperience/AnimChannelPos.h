/**
 * \file AnimChannelPos.h
 *
 * \author Tom Choi
 *
 * 
 */

#include "AnimChannel.h"
#include <gdiplus.h>
using namespace Gdiplus;
#include <memory>
#pragma once
/** pos
*/
class CAnimChannelPos :
	public CAnimChannel
{
public:
	CAnimChannelPos();
	virtual ~CAnimChannelPos();

	/** \brief Copy constructor disabled */
	CAnimChannelPos(const CAnimChannelPos&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelPos&) = delete;

	/** Get the Point
	* \returns mPoint Point
	*/
	Gdiplus::Point GetPoint() { return mPoint; }

	void SetKeyframe(Gdiplus::Point point);


	/** Class that represents a keyframe for an Point */
	class KeyframePoint : public CAnimChannel::Keyframe
	{
	public:

		/** Constructor
		* \param channel The channel we are for
		* \param point The Point for the keyframe */
		KeyframePoint(CAnimChannelPos* channel, Gdiplus::Point point) :
			Keyframe(channel), mChannel(channel), mPoint(point) {}

		/** Get the Point
		* \returns mPoint Point
		*/
		Gdiplus::Point GetPoint() { return mPoint; }

		/** Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** Use this keyframe as the Point */
		virtual void UseOnly() override { mChannel->mPoint = mPoint; }

	private:
		/// point for the keyframe
		Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

		/// The channel this keyframe is associated with
		CAnimChannelPos* mChannel;
	};

protected:
	void Tween(double t);

private:

	/// point for the channel
	Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

	/// The first Point keyframe
	KeyframePoint* mKeyframe1 = nullptr;

	/// The second Point keyframe
	KeyframePoint* mKeyframe2 = nullptr;
};

