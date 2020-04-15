
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

void genderToEnum(ANIMAL *animals, string gender,int i)
{
	if (gender == "male")
		animals[i].gender = gender::MALE;
	else if (gender == "female")
		animals[i].gender = gender::FEMALE;
}

void conditionToEnum(ANIMAL *animals, string condition, int i)
{
	if (condition == "good")
		animals[i].condition = condition::GOOD;
	else if (condition == "bad")
		animals[i].condition = condition::BAD;
}

void fillInAnimal(ANIMAL& newAnimal, string& gender, string& condition)
{
	cout << "Fill in the information about the animal" << endl;
	cout << endl;
	cout << "Name: ";
	cin >> newAnimal.name;
	cout << "Species: ";
	cin >> newAnimal.species;
	cin.ignore();
	cout << "Age (Years): ";
	cin >> newAnimal.age;
	cout << "Gender (male/femle): ";
	cin >> gender;
	cout << "Condition (good/bad): ";
	cin >> condition;
	cout << "Date of arrival (D/M/Y): ";
	cin >> newAnimal.dateOfArrival.day >> newAnimal.dateOfArrival.month >> newAnimal.dateOfArrival.year;
}

void addAnimal(ANIMAL *animals, int &animalCount,ANIMAL newAnimal)
{
	animals[animalCount] = newAnimal;
	animals[animalCount].id = animalCount+1;
	animalCount++;
}

void addAnimalMenu(ANIMAL* animals, int& animalCount)
{
	string gender, condition;

	ANIMAL newAnimal;
	
	fillInAnimal(newAnimal,gender,condition);

	addAnimal(animals,animalCount,newAnimal);

	genderToEnum(animals,gender,(animalCount-1));
	conditionToEnum(animals,condition,(animalCount-1));
}

void insertAnimal(ANIMAL* animals, int& animalCount, ANIMAL newAnimal,int index)
{
	for (int i = animalCount; i > index; i--)
	{
		animals[i] = animals[i - 1];
	}
	animals[index] = newAnimal;
	animals[index].id = animalCount + 1;
	animalCount++;
}

void insertAnimalMenu(ANIMAL* animals, int& animalCount)
{
	int index;
	string gender, condition;

	ANIMAL newAnimal;

	fillInAnimal(newAnimal, gender, condition);

	cout << endl;
	cout << "Enter the position where you want to place the animal: ";
	cin >> index;

	insertAnimal(animals, animalCount, newAnimal,index);

	genderToEnum(animals, gender, index);
	conditionToEnum(animals, condition, index);
}

int getIndexById(ANIMAL* animals, int animalCount,int idUser)
{
	int index;
	for (int i = 0; i < animalCount; i++)
	{
		if (animals[i].id == idUser)
			index = i;
	}

	return index;
}

void removeAnimal(ANIMAL* animals, int& animalCount,int index)
{
	for (int i = index; i < (animalCount - 1); i++)
	{
		animals[i] = animals[i + 1];
	}
	animalCount--;
}

void removeAnimalByIdMenu(ANIMAL* animals, int& animalCount,ANIMAL *adoptedAnimals, int &adoptedAnimalCount)
{
	int id,index;
	cout << "Enter animal's ID: ";
	cin >> id;

	index=getIndexById(animals,animalCount,id);

	cout << "\nEnter date of adoption (D/M/Y): ";
	cin >> animals[index].dateOfAdoption.day >> animals[index].dateOfAdoption.month >> animals[index].dateOfAdoption.year;

	addAnimal(adoptedAnimals, adoptedAnimalCount, animals[index]);
	removeAnimal(animals, animalCount, index);
}

void removeAnimalByIndexMenu(ANIMAL *animals, int &animalCount, ANIMAL* adoptedAnimals, int &adoptedAnimalCount)
{
	int index;
	cout << "Enter animal's position (index): ";
	cin >> index;

	cout << "\nEnter date of adoption (D/M/Y): ";
	cin >> animals[index].dateOfAdoption.day >> animals[index].dateOfAdoption.month >> animals[index].dateOfAdoption.year;

	addAnimal(adoptedAnimals, adoptedAnimalCount, animals[index]);
	removeAnimal(animals,animalCount,index);
}

void removeAnimalMenu(ANIMAL *animals, int &animalCount,ANIMAL *adoptedAnimals, int &adoptedAnimalCount)
{
	int choice;
	cout << "Do you want to remove an animal by: \n" << endl;
	cout << "1. Its ID\t 2. Its position in the list (index)\n" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:removeAnimalByIdMenu(animals,animalCount,adoptedAnimals,adoptedAnimalCount); break;
	case 2:removeAnimalByIndexMenu(animals,animalCount,adoptedAnimals, adoptedAnimalCount); break;
	}

	cout << "\nNote: once you remove an animal from the list of animals in the shelter, it will automatically be added to the list of adopted animals and its ID number will change \n" << endl;
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
		cout << endl;
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
		cout << endl;
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

void mainMenu(ANIMAL *animals,int &animalCount, ANIMAL *adoptedAnimals, int &adoptedAnimalCount)
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
	case 1:addAnimalMenu(animals,animalCount); break;
	case 2:insertAnimalMenu(animals, animalCount); break;
	case 3:removeAnimalMenu(animals,animalCount,adoptedAnimals, adoptedAnimalCount); break;
	/*case 4:updateAnimalMenu(); break;*/
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
	bool continueMenu = true;
	int animalCount = 15;
	int adoptedAnimalCount = 16;

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
	 {"Bolt",1, "dog",13,gender::MALE,condition::GOOD,{8,5,2008}, {2, 6, 2010}},
	 {"Perdita",2, "rabbit",0.5,gender::FEMALE,condition::GOOD,{12,8,2016}, {5, 10, 2017}},
	 {"Bubba",3, "fish",1,gender::FEMALE,condition::GOOD,{9,3,2018}, {5, 12, 2019}},
	 {"Lucky",4, "dog",3,gender::MALE,condition::BAD,{15,7,2019}, {4, 4, 2020}},
	 {"Rolly",5, "cat",1,gender::FEMALE,condition::BAD,{1,12,2019}, {1, 1, 2020}},
	 {"Sleepy",6, "dog",2,gender::MALE,condition::GOOD,{6,8,2018}, {8, 2, 2019}},
	 {"Purdy",7, "dog",0.5,gender::FEMALE,condition::GOOD,{23,3,2020}, {26, 3,2020}},
	 {"Dot",8, "cat",1,gender::MALE,condition::GOOD,{29,6,2019}, {30, 2, 2020}},
	 {"Sonic",9, "hedgehog",2,gender::MALE,condition::BAD,{27,7,2018}, {8, 1, 2019}},
	 {"Penny",10, "cat",1,gender::FEMALE,condition::GOOD,{5,11,2017}, {1, 12, 2017}},
	 {"Donatello",11, "turtle",6,gender::MALE,condition::GOOD,{4,2,2020}, {2, 3, 2020}},
	 {"Raphael",12, "turtle",4,gender::MALE,condition::BAD,{4,5,2018}, {30, 5, 2018}},
	 {"Thunder",13, "dog",5,gender::MALE,condition::BAD,{1,8,2016}, {6, 12, 2016}},
	 {"Freckles",14, "ferret",1,gender::MALE,condition::BAD,{4,10,2017}, {12,12,2017}},
	 {"Leonarado",15, "turtle",1,gender::MALE,condition::GOOD,{6,12,2018}, {1, 7, 2019}},
	 {"Pongo",16, "snake",0.5,gender::MALE,condition::GOOD,{8,5,2016}, {12, 6,2016}}
	};
	
	cout << "Hello! Welcome to Animal Help Rescue Center's registry (for now, the animals are sorted according to their date of arrival/adoption) \nHow may we assist you?"<<endl;
	
	do {
		mainMenu(animals, animalCount, adoptedAnimals, adoptedAnimalCount);
	} while (continueMenu == true);
}

