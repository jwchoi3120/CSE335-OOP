/**
 * \file BuildingCounter.h
 *
 * \author Tom Choi
 *
 * count buildings
 */

#pragma once
#include "TileVisitor.h"
 /**
  * count buildings
  */
class CBuildingCounter :
	public CTileVisitor
{
public:
	/** Get the number of buildings
	 * \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }
	/** Visit a CTileBuilding object
	* \param building Building we are visiting */
	void VisitBuilding(CTileBuilding* building);

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

