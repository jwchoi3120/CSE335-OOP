/**
 * \file Farm.cpp
 *
 * \author Tom Choi
 */

#include "Farm.h"
#include <iostream>
#include "leak.h"
using namespace std;
/**
* \brief Constructor
*/
CFarm::CFarm() 
{
}
/** \brief Destructor */
CFarm::~CFarm() 
{
	// Iterate over all of the animals, destroying 
	// each one.
	for (auto animal : mInventory)
	{
		delete animal;
	}

	// And clear the list
	mInventory.clear();
}
/** Add an animal to the farm inventory
*
* \param animal A animal to add to the inventory
*/
void CFarm::AddAnimal(CAnimal* animal)
{
	mInventory.push_back(animal);
}
/**
* Display the farm inventory.
*/
void CFarm::DisplayInventory()
{
	for (auto animal : mInventory)
	{
		animal->DisplayAnimal();
	}
}
/** Return how many females there are in a farm
*\return the number of females in a farm
*/
int CFarm::PrintFemaleNumber()
{
	int FemaleNumber = 0;
	for (auto animal : mInventory)
	{
		if (animal->IsFemale())
		{
			FemaleNumber++;
		}
	}
	return FemaleNumber;
}