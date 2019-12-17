/**
 * \file DecorCastle.h
 *
 * \author Tom Choi
 *
 * Class the implements a DecorCastle 
 */

#pragma once
#include <memory>
#include "Item.h"
#include <string>

using namespace std;
/**
*	Implement of DecorCastle Class
*
*/
class CDecorCastle :
	public CItem
{
public:
	CDecorCastle(CAquarium* aquarium);

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle&) = delete;
	/**
	* Save this item to an XML node
	* \param node The node we are going to be a child of
	* \return itemNode the node that we are returning
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

