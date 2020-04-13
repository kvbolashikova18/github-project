
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

enum gender{MALE,FEMALE};

enum condition{GOOD,BAD};

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

string genderToString(ANIMAL *animals,int i)
{
	string gender;
	if (animals[i].gender == 0)
		gender = "Male";
	else if (animals[i].gender == 1)
		gender = "Female";

	return gender;
}

string conditionToString(ANIMAL *animals, int i)
{
	string condition;
	if (animals[i].condition == 0)
		condition = "Good";
	else if (animals[i].condition == 1)
		condition = "Bad";
	return condition;
}

void showAnimal(ANIMAL *animals,int i,string gender,string condition)
{
	cout << "Name: " << animals[i].name << endl;
	cout << "ID: " << animals[i].id << endl;
	cout << "Species: " << animals[i].species << endl;
	cout << "Age (in human years): " << animals[i].age << endl;
	cout << "Gender: " << gender << endl;
	cout << "Condition: " << condition << endl;
	cout << "Date of arrival: " << animals[i].dateOfArrival.day << "/" << animals[i].dateOfArrival.month << "/" << animals[i].dateOfArrival.year << endl;
}

void showAdoptedAnimal(ANIMAL *adoptedAnimals, int i, string gender, string condition)
{
	cout << "Name: " << adoptedAnimals[i].name << endl;
	cout << "ID: " << adoptedAnimals[i].id << endl;
	cout << "Species: " << adoptedAnimals[i].species << endl;
	cout << "Age (in human years): " << adoptedAnimals[i].age << endl;
	cout << "Gender: " << gender << endl;
	cout << "Condition: " << condition << endl;
	cout << "Date of arrival: " << adoptedAnimals[i].dateOfArrival.day << "/" << adoptedAnimals[i].dateOfArrival.month << "/" << adoptedAnimals[i].dateOfArrival.year << endl;
	cout << "Date of adoption: " << adoptedAnimals[i].dateOfAdoption.day << "/" << adoptedAnimals[i].dateOfAdoption.month << "/" << adoptedAnimals[i].dateOfAdoption.year << endl;
}

void showAnimalsInShelter(ANIMAL *animals,int animalCount)
{
	string gender, condition;

	for (int i = 0; i < animalCount; i++)
	{
		gender = genderToString(animals, i);
		condition = conditionToString(animals, i);
		showAnimal(animals,i,gender,condition);
	}
	cout << endl;
}

void showAdoptedAnimals(ANIMAL *adoptedAnimals, int adoptedAnimalCount)
{
	string gender, condition;

	for (int i = 0; i < adoptedAnimalCount; i++)
	{
		gender = genderToString(adoptedAnimals, i);
		condition = conditionToString(adoptedAnimals, i);
		showAdoptedAnimal(adoptedAnimals, i, gender, condition);
	}
	cout << endl;
}

void showBySpecies(ANIMAL *animals, int animalCount,string speciesUser)
{
	string gender, condition;

	for (int i = 0; i < animalCount; i++)
	{
		gender = genderToString(animals, i);
		condition = conditionToString(animals, i);
		if (animals[i].species == speciesUser)
		{
			showAnimal(animals, i, gender, condition);
		}
	}
	cout << endl;
}

void showBySpeciesMenu(ANIMAL *animals, int animalCount)
{
	string speciesUser;
	cout << "Enter species: ";
	cin >> speciesUser;
	cout << endl;
	showBySpecies(animals,animalCount,speciesUser);
}

void showById(ANIMAL *animals, int animalCount, int IdUser)
{
	string gender, condition;

	for (int i = 0; i < animalCount; i++)
	{
		gender = genderToString(animals, i);
		condition = conditionToString(animals, i);
		if (animals[i].id == IdUser)
		{
			showAnimal(animals, i, gender, condition);
		}
	}
	cout << endl;
}

void showByIdMenu(ANIMAL *animals, int animalCount)
{
	int IdUser;
	cout << "Enter ID: ";
	cin >> IdUser;
	cout << endl;
	showById(animals, animalCount, IdUser);
}

void showIllAnimals(ANIMAL *animals, int animalCount)
{
	string gender, condition;

	for (int i = 0; i < animalCount; i++)
	{
		gender = genderToString(animals, i);
		condition = conditionToString(animals, i);

		if (animals[i].condition == condition::BAD)
		{
			showAnimal(animals, i, gender, condition);
		}
	}
	cout << endl;
}

void mainMenu(ANIMAL *animals,int animalCount, ANIMAL *adoptedAnimals, int adoptedAnimalCount)
{
	int choice;

	cout << endl;
	cout << "We rescued a new animal (add new animal to the registry:" << endl;
	cout << "1. Add to the end of the list" << endl;
	cout << "2. Add to a specific position on the list)" << endl;
	cout << "3. An animal got adopted (remove animal from the list of current animals and add to the adopted animals list)" << endl;
	cout << "4. Update an animal's profile" << endl;
	cout << "5. Show all animals in the shelter" << endl;
	cout << "6. Show all animals that have been adopted" << endl;
	cout << "7. Show animal by ID number" << endl;
	cout << "8. Show all animals of specific species" << endl;
	cout << "9. Show all animals that need medical treatment" << endl;
	cout << "10. EXIT" << endl;

	cout << endl;

	cout << "Choose an option: ";

	cin >> choice;

	cout << endl;

	switch (choice)
	{
	/*case 1:addAnimal(); break;
	case 2:insertAnimal(); break;
	case 3:removeAnimal(); break;
	case 4:updateAnimal(); break;*/
	case 5:showAnimalsInShelter(animals,animalCount); break;
	case 6:showAdoptedAnimals(adoptedAnimals,adoptedAnimalCount); break;
	case 7:showByIdMenu(animals, animalCount); break;
	case 8:showBySpeciesMenu(animals,animalCount); break;
	case 9:showIllAnimals(animals, animalCount); break;
	case 10: exit(0); break;
	}
}

int main()
{
	int animalCount = 15;
	int adoptedAnimalCount=1;

	ANIMAL animals[100] = {
	{"Oscar", 1, "cat", 6,gender::MALE,condition::GOOD,{4,7,2016}},
	{"Coco",2,"cat",3,gender::FEMALE,condition::GOOD,{8,10,2017}},
	{"Charlie",3,"dog",5,gender::MALE,condition::GOOD,{27,3,2017}},
	{"Ollie", 4, "turtle",2,gender::MALE,condition::GOOD,{30,6,2018}},
	{"Toby",5, "cat",3,gender::MALE, condition::BAD,{19,8,2019}},
	{"Ivy",6, "dog",2,gender::FEMALE, condition::BAD,{13,10,2019}},
	{"Tiger",7, "cat",1,gender::MALE, condition::GOOD, {8,11,2019}},
	{"Piper",8,"dog",3,gender::FEMALE, condition::BAD,{6,12,2019}},
	{"Clover",9,"rabbit",1,gender::MALE,condition::GOOD,{7,1,2020}},
	{"Chip",10, "squirrel",0.5,gender::MALE,condition::GOOD,{17,1,2020}},
	{"Twix",11,"hedgehog",1,gender::MALE,condition::GOOD,{9,2,2020}},
	{"Ella",12,"dog",2,gender::FEMALE,condition::BAD,{18,2,2020}},
	{"Milo",13, "cat",1,gender::MALE,condition::GOOD,{1,3,2020}},
	{"Daisy",14, "rabbit",0.5,gender::FEMALE,condition::BAD,{15,3,2020}},
	{"Swiper",15, "ferret", 0.5,gender::MALE,condition::GOOD,{2,4,2020}}
	};


	ANIMAL adoptedAnimals[100] = {
		{"Milo",13, "cat",1,gender::MALE,condition::GOOD,{1,3,2020}}
	};
	
	cout << "Hello! Welcome to Animal Help Rescue Center's registry (for now, the animals are sorted according to their date of arrival/adoption) \nHow may we assist you?"<<endl;
	
	mainMenu(animals,animalCount,adoptedAnimals,adoptedAnimalCount);
	
	system("PAUSE");
}

