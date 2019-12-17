/**
 * \file Neemo.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Neemo.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring NeemoImageName = L"images/nemo.png";
///speed for x
const double speedX = 10;
///speed for y
const double speedY = 10;
/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CNeemo::CNeemo(CAquarium* aquarium) :
	CFish(aquarium, NeemoImageName)
{
	this->UniqueSpeed(speedX, speedY);
}

std::shared_ptr<xmlnode::CXmlNode>
CNeemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"neemo");
	return itemNode;
}
