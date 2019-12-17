#include "pch.h"
#include "buyer.h"
#include "Address.h"
#include "Shoppingcart.h"
#include <string.h>
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;


Buyer::Buyer(char* Fname, char* Lname, char* bUsername, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber) : b_address(Country, City, Street, HomeNumber), b_Cart()
{
	bool indicator;
	indicator = setName(Fname, Lname);
	if (!indicator)
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
	if (!indicator)
	{
		do
		{
			cout << "Error in input for username, please enter again :" << endl;
			cin >> bUsername;
			indicator = setUsername(bUsername);

		} while (!indicator);

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

	cout << "Success in making a buyer" << endl; // just for testing.
}

bool Buyer::setName(char* firstName, char* lastName)
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
			return 0;
		}
	}

	for (i = 0; i < LNameLen; i++)
	{
		if (((lastName[i] < 'A') || (lastName[i] > 'Z')) && ((lastName[i] < 'a') || (lastName[i] > 'z')))
		{
			cout << "Invalid char in last name: " << lastName[i] << endl;
			return 0;
		}
	}

	b_Firstname = new char[maxLen];
	b_Lastname = new char[maxLen];
	strcpy(b_Firstname, firstName);
	strcpy(b_Lastname, lastName);

	return 1;
}

bool Buyer::setUsername(char* username)
{
	int len = strlen(username);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid username" << endl;
		return 0;
	}
	b_Username = new char[len];
	strcpy(b_Username, username);

	return 1;

}

bool Buyer::setPassword(char* password)
{
	int len = strlen(password);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid password" << endl;
		return 0;
	}
	b_Password = new char[len];
	strcpy(b_Password, password);

	return 1;

}


Buyer::~Buyer()
{
	delete[] b_Firstname;
	delete[] b_Lastname;
	delete[] b_Password;
	delete[] b_Username;

	if (TotalItemsIndex != 0)
	{
		//for (int i = 0; i < TotalItemsIndex; i++)
		//	delete ShoppingCart[i];

		//delete[]ShoppingCart;
	}
}

void Buyer::b_show() const
{
	cout << "Buyer name is: " << b_Firstname << " " << b_Lastname << endl;
	cout << "Living in: ";
	b_address.show();


}

char* Buyer::getUsername() const
{
	return b_Username;
}

char* Buyer::getPassword() const
{
	return b_Password;
}

int Buyer::getPurchasedFromSz() const
{
	return PurchasedFrom_sz;
}

Seller* Buyer::getSeller(const char* Sellername)
{
	int i;
	for (i = 0; i < PurchasedFrom_sz; i++)
	{
		if (strcmp(PurchasedFromArr[i]->getUsername(), Sellername) == 0)
			return PurchasedFromArr[i];
	}
	return nullptr;
}


void Buyer:: InsertItem(Item* item)
{
	b_Cart.AddItemToCart(*item);
}

void Buyer::UpdatePurchasedFromArr(Seller* TheSeller)
{
	if (PurchasedFrom_sz == 0) //First purchase
	{
		PurchasedFromArr = new Seller*[PurchasedFrom_sz + 1];
		PurchasedFromArr[0] = TheSeller;
		PurchasedFrom_sz++;
	}
	else
	{

		int i = 0;
		Seller** temp = new Seller*[PurchasedFrom_sz + 1]; // need to if already bought from the seller.
		for (i = 0; i < PurchasedFrom_sz; i++)
		{
			temp[i] = PurchasedFromArr[i];
		}
		temp[i] = TheSeller;
		delete[] PurchasedFromArr;
		PurchasedFromArr = temp;
		PurchasedFrom_sz++; 

	}
}

void Buyer :: showPurchasedFrom()
{
	int purchasedFrom = this->getPurchasedFromSz();
	if (purchasedFrom == 0)
	{
		cout << "you havent purchased any items yet" << endl;
		
	}
	else
	{
		cout << "sellers you purchased from are : " << endl;
		for (int i = 0; i < purchasedFrom; i++)
		{
			cout << i+1 <<" :" <<this->PurchasedFromArr[i]->getUsername() << endl;
		}
	}
}
//Buyer::Buyer(const Buyer& other)
//{
//	TotalItemsIndex = other.TotalItemsIndex;
//	b_FirstName = new char[strlen(other.b_FirstName) + 1];
//	strcpy(b_FirstName, other.b_FirstName);
//	b_LastName = new char[strlen(other.b_LastName) + 1];
//	strcpy(b_LastName, other.b_LastName);
//	b_Username = new char[strlen(other.b_Username) + 1];
//	strcpy(b_Username, other.b_Username);
//	b_Password = new char[strlen(other.b_Password) + 1];
//	strcpy(b_Password, other.b_Password);
//	b_address = new Address(other.b_address);
//	ShoppingCart = new Item* (*other.ShoppingCart);
//	FinalCart = new Item * (*other.FinalCart);
//
//}