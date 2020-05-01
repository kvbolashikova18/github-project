#include "pch.h"
#include <iostream>
#include <string>
#include "structures.h"
using namespace std;

string genderToString(ANIMAL* animals, int i)
{
	string gender;
	if (animals[i].gender == 0)
		gender = "Male";
	else if (animals[i].gender == 1)
		gender = "Female";

	return gender;
}