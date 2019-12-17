/**
 * \file Chicken.cpp
 *
 * \author Tom Choi
 */

#include <iostream>
#include "Chicken.h"
#include "Farm.h"
#include "Animal.h"

using namespace std;

/** Chicken object constructor.
*/
CChicken::CChicken()
{

}

/** Destructor.
*/
CChicken::~CChicken()
{

}

/** Obtain a chicken description from the user.
*/
void CChicken::ObtainChickenInformation()
{
	cout << endl;
	cout << "Input information about the chicken" << endl;

	// Obtain the ID. This is easy, since it's just a
	// string.
	cout << "Id: ";
	cin >> mId;
}

/** Display the chicken.
*/
void CChicken::DisplayAnimal()
{
	cout << "Chicken: " << mId << endl;
}
/** Check if chicken is female. Every chicken are female
*\return true
*/
bool CChicken::IsFemale() 
{
	return true;
}