/**
 * \file FishBeta.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "FishBeta.h"
#include "Fish.h"
#include <string>

using namespace std;
using namespace Gdiplus;

 /// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";
///speed for x
const double speedX = 5000;
///speed for x
const double speedY = 5000;
/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
	CFish(aquarium, FishBetaImageName)
{
	this->UniqueSpeed(speedX, speedY);
}

std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");
	return itemNode;
}
