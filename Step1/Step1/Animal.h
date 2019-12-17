/**
 * \file Animal.h
 *
 * \author Tom Choi
 *
 * Declartion of the Animal class.
 */

#pragma once
/**
* class that takes care of all the animals
*/
class CAnimal
{
public:
	virtual ~CAnimal();
	/** Display an animal. */
	virtual void DisplayAnimal() {};
	/** Check if the animal is female*/
	virtual bool IsFemale();
	
};

