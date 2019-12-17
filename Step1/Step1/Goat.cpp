/**
 * \file Goat.cpp
 *
 * \author Tom Choi
 */

#include "Goat.h"
#include <iostream>
#include "leak.h"
#include "Farm.h"
#include "Animal.h"

using namespace std;
/**
* Obtain information from the user about this goat.
*
* Asks the user for the information that describes a goat.
*/
void CGoat::ObtainGoatInformation()
{
	cout << endl;
	cout << "Input information about the goat" << endl;

	// Obtain the name. This is easy, since it's just a
	// string.
	cout << "Name: ";
	cin >> mName;

	// Obtain the type using a menu. We have a loop so
	// we can handle errors.
	bool valid = false;
	while (!valid)
	{
		cout << "1: Nanny" << endl;
		cout << "2: Billy" << endl;
		cout << "3: Wether" << endl;
		cout << "4: Male Kid" << endl;
		cout << "5: Female Kid" << endl;
		cout << "Enter selection and return: ";
		int option;
		cin >> option;
		if (!cin)
		{
			// We have an error. Clear the input and try again
			cin.clear();
			cin.ignore();
			continue;
		}

		switch (option)
		{
		case 1:
			mType = Nanny;
			valid = true;
			break;

		case 2:
			mType = Billy;
			valid = true;
			break;

		case 3:
			mType = Wether;
			valid = true;
			break;

		case 4:
			mType = MaleKid;
			valid = true;
			break;

		case 5:
			mType = FemaleKid;
			valid = true;
			break;
		}

	}
}
	
/**
 * Display information about this goat.
 */
void CGoat::DisplayAnimal()
{
	cout << mName << ": ";
	switch (mType)
	{
	case Nanny:
		cout << "Nanny Goat" << endl;
		break;

	case Billy:
		cout << "Billy Goat" << endl;
		break;

	case Wether:
		cout << "Wether Goat" << endl;
		break;

	case MaleKid:
		cout << "Male Kid Goat" << endl;
		break;

	case FemaleKid:
		cout << "Female Kid Goat" << endl;
		break;
	}
}
/** Check if goat is female
*\return true if female, false if male
*/
bool CGoat::IsFemale() 
{
	switch (mType)
	{
	case Nanny:
		return true;

	case Billy:
		return false;

	case Wether:
		return false;

	case MaleKid:
		return false;

	case FemaleKid:
		return true;
	}
}