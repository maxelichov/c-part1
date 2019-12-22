#pragma once
#include "pch.h"
#include "Seller.h"
#include "Address.h"
#include <string.h>
#include <iostream>

#define maxLen 31
#pragma warning(disable: 4996)
using namespace std;


Seller::Seller(char* Fname, char* Lname, char* bUsername, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber) : s_address(Country, City, Street, HomeNumber), s_Merch(), allFeedBacks()
{								// seller ctor //																						// send to address ctor //			// send to merchandise ctor // //send to feedback ctor//
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
}

bool Seller::setName(char* firstName, char* lastName)
{
	int fNameLen = strlen(firstName);
	int LNameLen = strlen(lastName);
	int i;

	if (fNameLen >= maxLen || fNameLen < 1)
	{
		cout << "Invalid First name" << endl;
		return false;
	}

	if (LNameLen >= maxLen || LNameLen < 1)
	{
		cout << "Invalid last name" << endl;
		return false;
	}

	for (i = 0; i < fNameLen; i++)
	{
		if (((firstName[i] < 'A') || (firstName[i] > 'Z')) && ((firstName[i] < 'a') || (firstName[i] > 'z')))
		{
			cout << "Invalid char in first name :" << firstName[i] << endl;
			return false;
		}
	}

	for (i = 0; i < LNameLen; i++)
	{
		if (((lastName[i] < 'A') || (lastName[i] > 'Z')) && ((lastName[i] < 'a') || (lastName[i] > 'z')))
		{		// making sure the name is valid //
			cout << "Invalid char in last name :" << lastName[i] << endl;
			return false;
		}
	}
	s_Firstname = strdup(firstName);
	s_Lastname = strdup(lastName);
	return true;
}

bool Seller::setUsername(char* username)
{
	int len = strlen(username);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid username" << endl;
		return false;
	}
	s_Username = strdup(username);

	return true;

}

bool Seller::setPassword(char* password)
{
	int len = strlen(password);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid password" << endl;
		return false;
	}
	s_Password = strdup(password);

	return true;

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
	cout << "Seller's stock is: " << endl;
	ShowStock();
	cout << endl;

}

char* Seller::getUsername() const
{
	return s_Username;
}

char* Seller::getPassword() const
{
	return s_Password;
}

void Seller::AddItemToStock(Item& NewItem,int Category)
{
	s_Merch.setItemToDepartment(NewItem, Category);
	NewItem.setSeller(this);
}

void Seller::addFeedback(char* feedback,char* BuyerName)
{
	allFeedBacks.AddFeedbackToSeller(feedback,BuyerName);
}

void Seller::ShowStock() const
{
	if (getCategoriesSize() == 0)
		cout << "Your item stock is empty!" << endl; 

	const char* Categories[] = { "Children" , "Clothing" , "Electricity" , "Office" };
	cout << "\nYour items are:\n";
	for (int i = 0; i < TotalDepartments; i++)
	{
		s_Merch.ShowDepartment(Categories[i]);
	}
	cout << endl;

}


int Seller::getCategoriesSize() const
{
	return(s_Merch.getNumOfDepartments());
}

bool Seller:: HaveCategory(const char* Category)
{
  return 	this->s_Merch.haveDepartment(Category);
}

void Seller::showCategoryItems(const char* Category)
{
	this->s_Merch.ShowDepartment(Category);
}

void Seller::DisplayItemByName(const char* ItemName,int& counter) 
{
	s_Merch.DisplayItemByName(ItemName,counter);
}

Item* Seller::getItem(const char* Category,int& SerialNumber)
{
	return this->s_Merch.getItemOfCategory(Category, SerialNumber);
}
