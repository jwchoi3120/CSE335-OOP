/**
 * \file Buddha.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Buddha.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring BuddhaImageName = L"images/buddha.png";
///speed for x position
const double speedX = 100;
///speed for y position
const double speedY = 100;
/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CBuddha::CBuddha(CAquarium* aquarium) :
	CFish(aquarium, BuddhaImageName)
{
	this->UniqueSpeed(speedX, speedY);
}

std::shared_ptr<xmlnode::CXmlNode>
CBuddha::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"buddha");
	return itemNode;
}
