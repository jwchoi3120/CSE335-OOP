/**
 * \file Goat.h
 *
 * \author Tom Choi
 *
 * Declartion of the CGoat class.
 */

#pragma once
#include <string>
#include "Animal.h"
/**
* Class that describes goat.
*/
class CGoat : public CAnimal
{
public:
	/// The types of goat we can have on our farm
	enum Type { Nanny, Billy, Wether, MaleKid, FemaleKid };
	void ObtainGoatInformation();
	/** Check if goat is female*/
	virtual bool IsFemale();
	void DisplayAnimal();
private:
	/// The goat's name
	std::string mName;
	/// The type of goat: Nanny, Billy, Wether, MaleKid, FemaleKid
	Type mType = Nanny;
};

