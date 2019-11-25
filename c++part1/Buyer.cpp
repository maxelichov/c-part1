#include "pch.h"
#include "buyer.h"
#include "Address.h"
#include <string.h>
#include <iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

Buyer::Buyer(char* Fname, char* Lname, Address& buyerAdress, char* bPassword)
{

	bool indicator;
	indicator = setName(Fname, Lname); // Maybe no need for the indicator
	if (!indicator)
	{
		do
		{


		} while (!setName(Fname, Lname));

	}

	/*if (setAddress(buyerAdress))
	{
		b_address = &buyerAdress;

	}*/



}

Buyer :: ~Buyer() /*d'tor*/
{
	/*delete[] b_name;
	delete[] b_password;*/
	/*b_address->~Address; */
	/*b_shopingCart;*/	/*need to create a shoping cart */
}


bool Buyer::setName(char* firstName, char* lastName)
{
	if (strlen(firstName) > maxNameLen || strlen(lastName) > maxNameLen) // One of the strings is too long.
	{
		cout << "Either first name or last name is longer than 25 chars" << endl;
		return 0;
	}
	int fNameLen = strlen(firstName);
	int LNameLen = strlen(lastName);
	int i;

	for (i = 0; i < fNameLen; i++)
	{
		if (firstName[i] < 'A' || ((firstName[i] > 'Z') && (firstName[i] < 'a')) || firstName[i] > 'z')
		{
			cout << "Invalid char in first name :" << firstName[i] << endl;
			return 0;
		}
	}

	for (i = 0; i < LNameLen; i++)
	{
		if (lastName[i] < 'A' || ((lastName[i] > 'Z') && (lastName[i] < 'a')) || lastName[i] > 'z')
		{
			cout << "Invalid char in last name :" << firstName[i] << endl;
			return 0;
		}

		b_FirstName = new char[maxNameLen];
		b_LastName = new char[maxNameLen];
		b_FirstName = firstName;
		b_LastName = lastName;
		return 1;
	}

	return 1;
}
