/**
 * \file Farm.h
 *
 * \author Tom Choi
 *
 * Class that decribes a Farm.
 * 
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#pragma once
#include <vector>
#include "Cow.h"
#include "Goat.h"
#include "Chicken.h"
#include "Animal.h"

/**
 * Class that describes a farm.
 *
 * Holds a collection of animals that make up the farm
 * inventory.
 */
class CFarm
{
public:
	CFarm();
	virtual ~CFarm();
	/** Add an animal to the farm inventory
	*\param animal A cow to add to the inventory
	*/
	void AddAnimal(CAnimal* animal);
	void DisplayInventory();
	/** Return how many females there are in a farm*/
	int PrintFemaleNumber();
private:
	/// A list with the inventory of all animals on the farm
	std::vector<CAnimal*> mInventory;
};

