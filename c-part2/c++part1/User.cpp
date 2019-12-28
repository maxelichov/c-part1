#include "User.h"
using namespace std;
#include <iostream>
#define maxLen 21

User::User(char* username, char* firstname, char* lastname, char* password,
	char* Country, char* City, char* Street, int& HomeNumber) : address(Country, City, Street, HomeNumber)
{
		bool indicator;
		indicator = setName(firstname, lastname);
		if (!indicator)
		{
			do
			{
				cout << "Error in the input, please try again!" << endl;
				cout << "Enter First name,press enter and then Last Name" << endl;
				cin >> firstname >> lastname;
				indicator = setName(firstname, lastname);

			} while (!indicator);
		}
		indicator = setUsername(username);
		if (!indicator)
		{
			do
			{
				cout << "Error in input for username, please enter again :" << endl;
				cin >> username;
				indicator = setUsername(username);

			} while (!indicator);

		}
		indicator = setPassword(password);
		if (!indicator)
		{
			do
			{
				cout << "Error in input for password, please enter again :" << endl;
				cin >> password;
				indicator = setPassword(password);

			} while (!indicator);

		}
	}

	bool User::setName(char* firstName, char* lastName)
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
				cout << "Invalid char in first name: " << firstName[i] << endl;
				return false;
			}
		}

		for (i = 0; i < LNameLen; i++)
		{
			if (((lastName[i] < 'A') || (lastName[i] > 'Z')) && ((lastName[i] < 'a') || (lastName[i] > 'z')))
			{
				cout << "Invalid char in last name: " << lastName[i] << endl;
				return false;
			}
		}

		FirstName = strdup(firstName);
		LastName = strdup(lastName);

		return true;
	}

	bool User::setUsername(char* username)
	{
		int len = strlen(username);
		if (len < 1 || len >= maxLen)
		{
			cout << "Invalid username" << endl;
			return false;
		}

		Username = strdup(username);

		return true;

	}

	bool User::setPassword(char* password)
	{
		int len = strlen(password);
		if (len < 1 || len >= maxLen)
		{
			cout << "Invalid password" << endl;
			return false;
		}
		Password = strdup(password);

		return true;

	}

	char* User::getUsername() const
	{
		return Username;
	}
	char* User:: getPassword() const
	{
		return Password;
	}
	
	char* User::getFirstName() const
	{
		return FirstName;
	}

	char* User::getLastName() const
	{
		return LastName;
	}
	void User::showAddress() const
	{
		address.show();
	}

	User::User(const User& other) : address(other.address)
	{
		*this = other;
	}

	User::~User()
	{
		delete[] FirstName;
		delete[] LastName;
		delete[] Username;
		delete[] Password;

	}