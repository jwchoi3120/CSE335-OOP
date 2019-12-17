/**
 * \file Fish.h
 *
 * \author Tom Choi
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 * 
 */

#pragma once
#include "Item.h"
#include "Aquarium.h"
/**
*	Implement of Fish Class
*
*
*/
class CFish :
	public CItem
{

public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish&) = delete;
	void Update(double elapsed);
	/**
	* Save the attributes for an item node.
	*
	* This is the  base class version that loads the attributes
	* common to all items. Override this to load custom attributes
	* for specific items.
	*
	* \param node The Xml node we are saving the item from
	* \return itemNode node
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/**
	* Load the attributes for an item node.
	*
	* This is the  base class version that loads the attributes
	* common to all items. Override this to load custom attributes
	* for specific items.
	*
	* \param node The Xml node we are loading the item from
	*/
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);
	/**
	*	Each fish has their own unique speed
	*	\param speedX speed of X position
	*	\param speedY speed of Y position
	*/
	virtual void UniqueSpeed(const double speedX, const double speedY);
private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
protected:
	/** Fish constructor
	* \param aquarium aquarium
	* \param filename name of a file
	*/
	CFish(CAquarium* aquarium, const std::wstring& filename);

};

