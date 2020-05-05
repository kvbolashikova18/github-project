#include "pch.h"
#include <iostream>
#include <string>
#include "structuresAndEnums.h"
using namespace std;

//converts the animal's gender from enum to string
string genderToString(ANIMAL *animals, int i)
{
	string gender;
	if (animals[i].gender == 0)
		gender = "Male";
	else if (animals[i].gender == 1)
		gender = "Female";

	return gender;
}