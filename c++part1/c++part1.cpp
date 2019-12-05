
#pragma once

#include "pch.h"
#include <iostream>
#include "Address.h"
#include "Buyer.h"
#include "Seller.h"
//#include "Feedback.h"
//#include "Item.h"
//#include "Shoppingcart.h"
#include <stdio.h>
#include "sellersmerch.h"
using namespace std;

#define maxLen 31

using namespace std;
constexpr auto EXIT = 11;

//FUNCTION'S DECLARATIONS :

/*Buyer** ResizeBuyersArr(Buyer** Arr, int Logsize, int PhysSize);
Seller** ResizeSellersArr(Seller** Arr, int Logsize, int PhysSize);
void displayMenu();
bool validateChoice(int& MenuChoice);
void ExecuteChoice(int& MenuChoice, Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize);
void addUser(Buyer*** AllBuyers, int& TotalBuyerslogSize, int& TotalBuyersPhysSize, int& Choice, Seller*** AllSellers, int& TotalSellerslogSize,
	int& TotalSellersPhysSize);
void cleanBuffer();*/




/*void addItemToSellersStock()
{
	cout << "enter the name of the item" << endl;
	char* itemName = cin.get;
}*/





int main()
{
	/*int MenuChoice;
	bool Input;
	int TotalBuyerslogSize = 0, TotalBuyersPhysSize = 1;
	int TotalSellerslogSize = 0, TotalSellersPhysSize = 1;
	Buyer** AllBuyers = nullptr;
	Seller** AllSellers = nullptr;

	do {
		displayMenu();
		cin >> MenuChoice;
		Input = validateChoice(MenuChoice);
		cleanBuffer();

		if (Input)
			ExecuteChoice(MenuChoice, &AllBuyers, TotalBuyerslogSize, TotalBuyersPhysSize, &AllSellers,
				TotalSellerslogSize, TotalSellersPhysSize);

		else
			cout << "Invalid number entered please try again!" << endl;

	} while (MenuChoice != EXIT);

	cout << "Exiting Program";

	return 1;

}



void displayMenu()
{

	cout << "Welcome to our Interactive Menu please choose one of the following by entering the number of it :" << endl;
	cout << "1. Add a buyer " << endl << "2. Add a seller " << endl << "3. Add an item to a seller"
		<< endl << "4. Add a feedback to a seller" << endl << "5. Add an item to your shopping cart" <<
		endl << "6. Make an order" << endl << "7. Make a payment " << endl << "8. Show all buyers info" <<
		endl << "9. Show all Sellers info" << endl << "10. Show All the Items with the same name" << endl << "11. Exit program" << endl;

}

bool validateChoice(int& MenuChoice) // sending by ref for efficency //
{
	if (MenuChoice >= 1 && MenuChoice <= 11)
		return 1;
	else
		return 0;

}

void ExecuteChoice(int& MenuChoice, Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize)
{
	switch (MenuChoice) // Need to add more cases
	{
	case 1: // Add buyer case
		addUser(AllBuyers, TotalBuyersLogSize, TotalBuyersPhysSize, MenuChoice, AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
		break;
	case 2: // Add seller case
		addUser(AllBuyers, TotalBuyersLogSize, TotalBuyersPhysSize, MenuChoice, AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
		break;

	}

}

void addUser(Buyer*** AllBuyers, int& TotalBuyerslogSize, int& TotalBuyersPhysSize, int& Choice, Seller*** AllSellers, int& TotalSellerslogSize,
	int& TotalSellersPhysSize) // function for both to add buyer and seller instead of 2 funcs.
{

	char fname[maxLen], lname[maxLen], password[maxLen], username[maxLen], country[maxLen],
		city[maxLen], street[maxLen];
	int homenumber;

	cout << "Please fill out our form in order to make a new user :" << endl;
	cout << "Enter first name (Max 30 chars and only letters) : " << endl;
	cin >> fname;
	cout << "Enter last name (Max 30 chars and only letters) : " << endl;
	cin >> lname;
	cout << "Enter Username (Max 30 chars) : " << endl;
	cin >> username;
	cout << "Enter Password (Max 30 chars) :" << endl;
	cin >> password;
	cout << "Enter Country,press enter and then a City (Max 30 chars per location)  :" << endl;
	cleanBuffer();
	cin.getline(country, maxLen);
	cin.getline(city, maxLen);
	cout << "Enter Street,press enter and then Homenumber :" << endl;
	cin.getline(street, maxLen);
	cin >> homenumber;

	if (Choice == 1) // need to add buyer.
	{
		if (*AllBuyers == nullptr) // If the array of pointers to buyers is null then make a room for one.
			*AllBuyers = new Buyer *[TotalBuyersPhysSize];

		else if (TotalBuyerslogSize == TotalBuyersPhysSize) // need to make more size into the buyers arr.
		{
			TotalBuyersPhysSize *= 2;
			*AllBuyers = ResizeBuyersArr(*AllBuyers, TotalBuyerslogSize, TotalBuyersPhysSize);
		}

		(*AllBuyers)[TotalBuyerslogSize] = new Buyer(fname, lname, username, password, country, city, street, homenumber); // make the new buyer
		TotalBuyerslogSize++; // increase the buyers total number by 1.
	}
	else // meaning we need to add seller
	{

		if (*AllSellers == nullptr)
			*AllSellers = new Seller *[TotalSellersPhysSize];

		else if (TotalSellerslogSize == TotalSellersPhysSize)
		{
			TotalSellersPhysSize *= 2;
			*AllSellers = ResizeSellersArr(*AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
		}

		(*AllSellers)[TotalSellerslogSize] = new Seller(fname, lname, username, password, country, city, street, homenumber); // make the new seller
		TotalSellerslogSize++;
	}

}


void cleanBuffer()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}


Buyer** ResizeBuyersArr(Buyer** Arr, int Logsize, int PhysSize) // Increase buyers arr
{
	Buyer** NewArr = new Buyer *[PhysSize];

	memcpy(NewArr, Arr, Logsize * sizeof(Buyer*)); // Copy the pointers from old Arr to NewArr with bigger size.

	delete[]Arr;

	return NewArr;
}

Seller** ResizeSellersArr(Seller** Arr, int Logsize, int PhysSize) // Increase sellers arr
{
	Seller** NewArr = new Seller *[PhysSize];

	memcpy(NewArr, Arr, Logsize * sizeof(Seller*)); // Copy the pointers from old Arr to NewArr with bigger size.

	delete[]Arr;

	return NewArr;*/
		
char name[] = "toyCar";
char secondName[] = "sometoy";
char serialNum[] = "123abc";
char secondSerialNum[] = "321xyz";
int price = 50;
	int x,  y;
	char fname[] = "max";
	char lname[] = "elichov";
	char password[] = "12345";
	char username[] = "maxelichov99";
	char country[] = "israel";
	char city[] = "tel aviv";
	char street[] = "nahlat binyamin";
	int homenumber = 9;
	eCategory itemCategory = (eCategory)1;
	eCategory second = (eCategory)1;
	Merchandise sellerMerch;
	Item newItem(name, price, serialNum, itemCategory);
	Item secondItem(secondName, 40, secondSerialNum, second);
	Department dep(itemCategory);
	dep.addItem(newItem);
	dep.addItem(secondItem);

	//Seller testSeller(fname , lname, username, password, country, city, street, homenumber);
	//testSeller.AddItemToStock(newItem);
		
/*	testSeller.AddItemToStock(newItem);*/
	 // now we need to add an item to sellers merchandise //

	

}