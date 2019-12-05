#include "pch.h"
#include "Seller.h"
#include "Address.h"
#include <string.h>
#include <iostream>
#define maxLen 31
#pragma warning(disable: 4996)
using namespace std;


Seller::Seller(char* Fname, char* Lname, char* bUsername, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber) : s_address(Country, City, Street, HomeNumber)
{								// seller ctor //																						// send to address ctor //								// send to merchandise ctor //
	bool indicator;
	indicator = setName(Fname, Lname);
	if (indicator == 0)
	{
		do
		{
			cout << "Error in the input, please try again!" << endl;
			cout << "Enter First name,press enter and then Last Name" << endl;
			cin >> Fname >> Lname;
			indicator = setName(Fname, Lname);

		} while (!indicator);
	}
	indicator = setUsername(bUsername);
	if (indicator == 0)
	{
		do
		{
			cout << "Error in input for username, please enter again :" << endl;
			cin >> bUsername;
			indicator = setUsername(bUsername);

		} while (indicator == 0);

	}
	indicator = setPassword(bPassword);
	if (!indicator)
	{
		do
		{
			cout << "Error in input for password, please enter again :" << endl;
			cin >> bPassword;
			indicator = setPassword(bPassword);

		} while (!indicator);

	}

	cout << "Success in making a seller" << endl; // just for testing.
}

bool Seller::setName(char* firstName, char* lastName)
{
	int fNameLen = strlen(firstName);
	int LNameLen = strlen(lastName);
	int i;

	if (fNameLen >= maxLen || fNameLen < 1)
	{
		cout << "Invalid First name" << endl;
		return 0;
	}

	if (LNameLen >= maxLen || LNameLen < 1)
	{
		cout << "Invalid last name" << endl;
		return 0;
	}

	for (i = 0; i < fNameLen; i++)
	{
		if (((firstName[i] < 'A') || (firstName[i] > 'Z')) && ((firstName[i] < 'a') || (firstName[i] > 'z')))
		{		
			cout << "Invalid char in first name :" << firstName[i] << endl;
			return 0;
		}
	}

	for (i = 0; i < LNameLen; i++)
	{
		if (((lastName[i] < 'A') || (lastName[i] > 'Z')) && ((lastName[i] < 'a') || (lastName[i] > 'z'))) 
		{		// making sure the name is valid //
			cout << "Invalid char in last name :" << lastName[i] << endl;
			return 0;
		}
	}
	s_Firstname = new char[maxLen];
	s_Lastname = new char[maxLen];
	strcpy(s_Firstname, firstName);
	strcpy(s_Lastname, lastName);
	return 1;
	 // two returns? //
	return 1;
}

bool Seller::setUsername(char* username)
{
	int len = strlen(username);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid username" << endl;
		return 0;
	}
	s_Username = new char[len];
	strcpy(s_Username, username);

	return 1;

}

bool Seller::setPassword(char* password)
{
	int len = strlen(password);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid password" << endl;
		return 0;
	}
	s_Password = new char[len];
	strcpy(s_Password, password);

	return 1;

}

void Seller :: AddItemToStock(Item& NewItem)
{
	/*int department = NewItem.getItemCategory(); // need to declate friend method? //
	
	/*need to allocate and insert the new item to the department/
	s_Stock.setItemToDepartment(NewItem, department); /*sending the depIndex and the item/
	*/
	
	return;
}


Seller::~Seller() // D'TOR
{
	delete[] s_Firstname;
	delete[] s_Lastname;
	delete[] s_Password;
	delete[] s_Username;

}

void Seller::s_show() const
{
	cout << "Seller's name is: " << s_Firstname << " " << s_Lastname << endl;
	cout << "Living in: ";
	s_address.show();


}

/*int checkCategory(Seller& seller)
{
	
}*/