/**
 * \file Fish.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Fish.h"
/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */

 /// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 800;
/// Maximum speed in the Y direction in
 /// in pixels per second
const double MaxSpeedY = 800;
/// Minimum speed in the X direction in
 /// in pixels per second
const double MinSpeedX = 50;
/// Minimum speed in the Y direction in
 /// in pixels per second
const double MinSpeedY = 50;
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
	CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if (mSpeedX > 0 && GetX() >= (GetAquarium()->GetWidth() - 10 - (GetFishWidth() / 2 )))
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	else if (mSpeedX < 0 && GetX() <= (10 + (GetFishWidth() / 2)))
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	if (mSpeedY > 0 && GetY() >= (GetAquarium()->GetHeight() - 10 - (GetFishHeight() / 2)))
	{
		mSpeedY = -mSpeedY;
	}

	else if (mSpeedY < 0 && GetY() <= (10 + (GetFishHeight() / 2)))
	{
		mSpeedY = -mSpeedY;
	}
}

std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"speedx", mSpeedX);
	itemNode->SetAttribute(L"speedy", mSpeedY);
	return itemNode;
}

void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);

	if (mSpeedX < 0)
	{
		SetMirror(mSpeedX < 0);
	}
}

void CFish::UniqueSpeed(const double speedX, const double speedY)
{
	mSpeedX = ((double)rand() / RAND_MAX) * speedX;
	mSpeedY = ((double)rand() / RAND_MAX) * speedY;
}