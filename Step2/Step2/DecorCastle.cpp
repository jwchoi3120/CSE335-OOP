/**
 * \file DecorCastle.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "DecorCastle.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CastleImageName = L"images/castle.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
	CItem(aquarium, CastleImageName)
{
}

std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"castle");
	return itemNode;
}