/**
 * \file FixVisitor.h
 *
 * \author Tom Choi
 * 
 * check if it visited
 */

#pragma once
#include "TileVisitor.h"
#include "IsRoadVisitor.h"

 /**
  * check if it visited
  */
class CFixVisitor :
	public CTileVisitor
{
public:
	/** \brief Visit a CTileRoad object
	* \param road road tile we are visiting */
	virtual void VisitRoad(CTileRoad* road) override;
};

