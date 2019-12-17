/**
 * \file Buddha.h
 *
 * \author Tom Choi
 *
 * Class the implements a Buddha
 */

#pragma once
#include <memory>
#include "Item.h"
#include "Fish.h"
#include <string>

using namespace std;
/**
*	Implement of Buddha Class
*
*/
class CBuddha :
	public CFish
{
public:
	CBuddha(CAquarium* aquarium);

	/// Default constructor (disabled)
	CBuddha() = delete;

	/// Copy constructor (disabled)
	CBuddha(const CBuddha&) = delete;

	/**
	* Save this item to an XML node
	* \param node The node we are going to be a child of
	* \return itemNode 
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};



