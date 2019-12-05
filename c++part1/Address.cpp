#include "pch.h"
#include "Address.h"
#include <string.h>
#include "Buyer.h"
#include "Seller.h"
//#include "Shoppingcart.h"
#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#define MAX_HOMENUM 300

Address::Address(char* Country, char* City, char* Street, int& HomeNumber) // C'TOR
{
	bool indicator;
	indicator = setLocation(Country, 0);
	if (!indicator)
	{
		do {
			cout << "Invalid text in Country, please try again" << endl << "Enter Country :" << endl;
			cin >> Country;
			indicator = setLocation(Country, 0);

		} while (!indicator);
	}

	indicator = setLocation(City, 1);
	if (!indicator)
	{
		do {
			cout << "Invalid text in City, please try again" << endl << "Enter City :" << endl;
			cin >> City;
			indicator = setLocation(City, 1);


		} while (!indicator);
	}

	indicator = setLocation(Street, 2);
	if (!indicator)
	{
		do {
			cout << "Invalid text in Street, please try again" << endl << "Enter Street :" << endl;
			cin >> Street;
			indicator = setLocation(Street, 2);

		} while (!indicator);
	}
	indicator = setHomeNumber(HomeNumber);
	if (!indicator)
	{
		do {
			cout << "Home number needs to be between 1 to 300 " << endl << "Enter home number :" << endl;
			cin >> HomeNumber;
			indicator = setHomeNumber(HomeNumber);
		} while (!indicator);

	}

}


bool Address::setLocation(char* location, int flag) // if flag == 0 set country , 1 == set city , 2 == set street , general func for all locations.
{
	int len = strlen(location);
	if (len == 0 || len >= maxLen)
		return 0;

	for (int i = 0; i < len; i++)
	{
		if (location[i] < 'A' || ((location[i] > 'Z') && (location[i] < 'a')) || location[i] > 'z')
		{
			if (location[i] == ' ')
			{
				if (i >= 1 && i < maxLen)
				{
					if (location[i - 1] < 'A' || ((location[i - 1] > 'Z') && (location[i - 1] < 'a')) || location[i - 1] > 'z')
						return 0;
					if (location[i + 1] < 'A' || ((location[i + 1] > 'Z') && (location[i + 1] < 'a')) || location[i + 1] > 'z')
						return 0;
				}
				else
					return 0;
			}
			else
				return 0;

		}
	}

	if (flag == 0) {
		Country = new char[strlen(location) + 1];
		strcpy(Country, location);
		return 1;

	}
	else if (flag == 1)
	{
		City = new char[strlen(location) + 1];
		strcpy(City, location);
		return 1;

	}
	else if (flag == 2)
	{
		Street = new char[strlen(location) + 1];
		strcpy(Street, location);
		return 1;
	}
	else
		return 0;
}

bool Address::setHomeNumber(int homenumber)
{
	if (homenumber <= 0 || homenumber > MAX_HOMENUM)
		return 0;

	else
		HomeNumber = homenumber;

	return 1;
}

void Address::show() const
{
	cout << Country << ", " << City << endl << Street <<
		", " << HomeNumber << endl;

}

Address:: ~Address() // D'TOR
{
	delete[] Country;
	delete[] City;
	delete[]Street;

}