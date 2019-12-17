/**
 * \file Cow.h
 *
 * \author Tom Choi
 *
 * Declartion of the CCow class.
 */

#pragma once
#include <string>
#include "Animal.h"
/**
* Class that describes cow.
*/
class CCow : public CAnimal
{
public:
	/// The types of cow we can have on our farm
	enum Type {Bull, BeefCow, MilkCow};
	void ObtainCowInformation();
	void DisplayAnimal();
	/** Check if cow is female*/
	virtual bool IsFemale();
private:
	/// The cow's name
	std::string mName;
	
	/// The type of cow: Bull, BeefCow, or MilkCow
	Type mType = MilkCow;

	///The milk production for a cow in gallans per day
	double mMilkProduction = 0;
};

