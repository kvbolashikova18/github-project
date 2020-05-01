#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

enum gender { MALE, FEMALE };

enum condition { GOOD, BAD };

struct DATE
{
	int day;
	int month;
	int year;
};

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