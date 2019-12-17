/**
 * \file Stinky.h
 *
 * \author Tom Choi
 *
 * Class the implements a Stinky fish
 */

#pragma once
#include <memory>
#include "Item.h"
#include <string>

using namespace std;
/**
*	Implement of Stinky Fish Class
*
*/
class CStinky :
	public CItem
{
public:
	CStinky(CAquarium* aquarium);

	/// Default constructor (disabled)
	CStinky() = delete;

	/// Copy constructor (disabled)
	CStinky(const CStinky&) = delete;

	/**set the location of fish
	* \param x x position
	* \param y y position
	*/
	virtual void SetLocation(double x, double y) override;
};
