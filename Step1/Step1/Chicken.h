/**
 * \file Chicken.h
 *
 * \author Tom Choi
 *
 * Declartion of the CChicken class.
 */

#pragma once
#include <string>
#include "Animal.h"

 /** Class that describes a chicken.
 */
class CChicken : public CAnimal
{
public:
	CChicken();
	virtual ~CChicken();
	/** Check if chicken is female. Every chicken are female*/
	virtual bool IsFemale();
	void ObtainChickenInformation();
	void DisplayAnimal();

private:
	//! The chicken's ID
	std::string mId;
};

