/**
 * \file IsRoadVisitor.h
 *
 * \author Tom Choi
 *
 * check if it visited
 */

#pragma once
#include "TileVisitor.h"
/**
* check if it visited
*/
class CIsRoadVisitor :
	public CTileVisitor
{
public:
	/** check if it is visited
	* \param road
	*/
	virtual void VisitRoad(CTileRoad* road) override;
	/** check if it is visited
	* \return mIsRoad
	*/
	bool IsRoad() { return mIsRoad; }

private:
	/** member of road*/
	bool mIsRoad = false;
};

