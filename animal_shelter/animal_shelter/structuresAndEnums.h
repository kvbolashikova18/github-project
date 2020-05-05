#pragma once
#include "pch.h"
#include <string>
using namespace std;

//enum for the animal's gender
enum gender { MALE, FEMALE };

//enum for the animal's condition
enum condition { GOOD, BAD };

//structure for the date
struct DATE
{
	int day;
	int month;
	int year;
};

//structure with information about the animal
struct ANIMAL
{
	string name;
	int id;
	string species;
	float age;
	gender gender;
	condition condition;
	DATE dateOfArrival;
	DATE dateOfAdoption;
};
