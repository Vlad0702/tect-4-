#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;


struct Patient
{
	char FirstName[15],
		SecondName[15],
		LastName[15],
		Sex[7],
		Nationality[56],
		Address[255],
		Hospital[4],
		MedCard[10],
		Diagnosis[255],
		Number[56],
		Branch[25],
		Blood[4];

	int Age,
		Height,
		Weight,
	   year;
};

Patient* InitArray(int Dimension);
Patient InitPerson();
void DisplayArray(Patient* Massive, int Dimaension);
void DisplayChoise(Patient*, int, char*, int, int);
void DisplayPerson(Patient);
void SortFirstName(Patient*, int);
int& CheckCorectDigitValue(int&);

void main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");

	int Dimension;
	char SexTag[7];
	int LowAge, UpperAge;
	bool begin = true;
tryagain:
	Patient* MassiveStruct = nullptr;
	do
	{
		cout << "\nEnter the number of books:  ";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "[!]Input Error! try again" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n[!]Dynamic array don't exist!\n";

			do {
				cout << "[!]Enter '+' to try again or press '-' to exit the program... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\nAll information: " << endl;
	DisplayArray(MassiveStruct, Dimension);


	delete MassiveStruct;
}
Patient InitPerson()
{
	setlocale(LC_ALL, "Russian");
	Patient Man;

	cout << "\nEnter author surname: ";
	garbage_collector();
	cin.getline(Man.SecondName, 255);

	cout << "Enter author name: ";
	garbage_collector();
	cin.getline(Man.FirstName, 255);

	cout << "Enter the middle name of the author: ";
	garbage_collector();
	cin.getline(Man.LastName, 255);

	cout << "Enter book title: ";
	garbage_collector();
	cin.getline(Man.Nationality, 255);

	cout << "Enter the cost price: ";
	garbage_collector();
	cin >> Man.Height;

	cout << "Enter price: ";
	garbage_collector();
	cin >> Man.Weight;

    cout << "Enter year of issue: ";
		garbage_collector();
		cin >> Man.year ;
	

	cout << "Enter profit: ";
	garbage_collector();
	cin.getline(Man.Hospital, 4);

	
	return Man;
}

Patient* InitArray(int Dimension)
{
	Patient* Massive = new Patient[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\nEnter the %d information of the book: ", i + 1);
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Patient* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}

void DisplayChoise(Patient* Massive, int Dimension, char* SexTag, int LowAge, int UpperAge)
{
	for (size_t i = 0; i < Dimension; i++)
	{
		if (
			strcmp(Massive[i].Sex, SexTag) == 0 &&
			Massive[i].Age <= UpperAge &&
			Massive[i].Age >= LowAge
			)
		{
			DisplayPerson(Massive[i]);
		}
	}
}

void DisplayPerson(Patient Man)
{
	setlocale(LC_ALL, "Russian");
	cout << "Name of the author: " << Man.FirstName << " " << Man.SecondName << " " << Man.LastName << endl;
	cout << "Cost price: " << Man.Height << endl;
	cout << "Price: " << Man.Weight << endl;
	cout << "Year of issue: " << Man.year << endl;
	cout << "Book title: " << Man.Nationality << endl;
	cout << "Profit: " << Man.Hospital << endl;
}
void SortFirstName(Patient* Massive, int Dimension)
{
	Patient Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)

				Temp = Massive[q];
			Massive[q] = Massive[q - 1];
			Massive[q - 1] = Temp;

		}
	}
}

int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "[!]try again";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}