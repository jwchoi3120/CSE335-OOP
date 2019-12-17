#include "pch.h"
#include "FixVisitor.h"
#include "TileRoad.h"


void CFixVisitor::VisitRoad(CTileRoad* road)
{

	
	auto ulTile = road->GetAdjacent(-1, -1);
	auto urTile = road->GetAdjacent(1, -1);
	auto llTile = road->GetAdjacent(-1, 1);
	auto lrTile = road->GetAdjacent(1, 1);

	bool ul = false;
	bool ur = false;
	bool ll = false;
	bool lr = false;


	if (ulTile != nullptr) {
		CIsRoadVisitor visitor;
		ulTile->Accept(&visitor);
		ul = visitor.IsRoad();
	}
	if (urTile != nullptr) {
		CIsRoadVisitor visitor;
		urTile->Accept(&visitor);
		ur = visitor.IsRoad();
	}
	if (llTile != nullptr) {
		CIsRoadVisitor visitor;
		llTile->Accept(&visitor);
		ll = visitor.IsRoad();
	}
	if (lrTile != nullptr) {
		CIsRoadVisitor visitor;
		lrTile->Accept(&visitor);
		lr = visitor.IsRoad();
	}

	road->SetAdjacencies(ul, ur, ll, lr);
}