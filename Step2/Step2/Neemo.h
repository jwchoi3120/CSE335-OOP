/**
 * \file Neemo.h
 *
 * \author Tom Choi
 *
 * Class the implements a Neemo
 */

#pragma once
#include <memory>
#include "Item.h"
#include "Fish.h"
#include <string>

using namespace std;
/**
*	Implement of Neemo Class
*
*/
class CNeemo :
	public CFish
{
public:
	CNeemo(CAquarium* aquarium);

	/// Default constructor (disabled)
	CNeemo() = delete;

	/// Copy constructor (disabled)
	CNeemo(const CNeemo&) = delete;

	/**
	* Save the attributes for an item node.
	*
	* This is the  base class version that saves the attributes
	* common to all items. Override this to save custom attributes
	* for specific items.
	*
	* \param node The Xml node we are loading the item from
	* \return itemNode node
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};




