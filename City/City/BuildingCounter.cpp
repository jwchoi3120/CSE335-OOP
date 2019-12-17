#include "pch.h"
#include "BuildingCounter.h"
void CBuildingCounter::VisitBuilding(CTileBuilding* building)
{
	mNumBuildings++;
}