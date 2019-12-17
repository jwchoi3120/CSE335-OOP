/**
 * \file FishBeta.h
 *
 * \author Tom Choi
 *
 * Class the implements a Beta Fish
 */

#pragma once
#include <memory>
#include "Item.h"
#include "Fish.h"
#include <string>

using namespace std;
/**
*	Implement of FishBeta Class
*
*/
class CFishBeta :
	public CFish
{
public:
	CFishBeta(CAquarium* aquarium);

	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;
	
	/**
	* Save this item to an XML node
	* \param node The node we are going to be a child of
	* \return itemNode node
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

