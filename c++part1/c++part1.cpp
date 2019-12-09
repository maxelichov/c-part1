#pragma once
#include "pch.h"
#include "Item.h"
#include <iostream>
#include "Address.h"
#include "Buyer.h"
#include "Seller.h"
//#include "Feedback.h"
//#include "Shoppingcart.h"
#include <stdio.h>
#include "Merchandise.h"
#include "ItemNode.h"

using namespace std;
#define maxFidbackLen 100
#define maxLen 31
using namespace std;
#define EXIT 11
const char* Categories[] = { "Children" , "Clothing" , "Electricity" , "Office" };
#define TotalCategories 4

//FUNCTION'S DECLARATIONS :


void displayMenu();
bool validateChoice(int& MenuChoice);
void ExecuteChoice(int& MenuChoice, Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize);
void addUser(Buyer*** AllBuyers, int& TotalBuyerslogSize, int& TotalBuyersPhysSize, int& Choice, Seller*** AllSellers, int& TotalSellerslogSize,
	int& TotalSellersPhysSize);
void cleanBuffer();
void addItem(Seller** Sellers, int& size);
void AddtoSeller(Seller* Sellers, int& index);
void addItemToSeller(Seller* Sellers, int& index, Item* item);


int main()
{
	int MenuChoice;
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
		case 3: // Add new item to seller
		addItem(*AllSellers,TotalSellerslogSize);
		case 4: // add fidback to seller
			addFidback(*AllBuyers, *AllSellers , TotalSellerslogSize); // TODO
	}
}
bool FindSeller(Seller** AllSellers, int* position , int TotalSellerslogSize , char* name)  //
{
	//function that checks if the seller exists //
	for (int i = 0; i < TotalSellerslogSize; i++)
	{
		if (strcmp(AllSellers[i]->getUsername, name) == 0)
		{
			return true;
		}
		*position++;
	}
	return false;
}

void GiveFidbackToSeller(Seller* TheSeller , char* fidback) // friend fucntion of Seller obj? //
{
	
}
void addFidback(Buyer** AllBuyers, Seller** AllSellers , int TotalSellerslogSize)
{	/*need to login as buyers before adding a fidback*/
	int position = 0;
	char fidback[maxFidbackLen];
	char SellerName[maxLen];
	cout << "please enter the user name of the seller you wish to give a fidback to " << endl;
	
	bool found = FindSeller(AllSellers, &position , TotalSellerslogSize , SellerName);
	if (!found)
	cout << "the name you enterd does not exist in the system. please try again." << endl; 
	else
	{
			/* bool ifPurchased == true*/					// need to check if buyer purchased from seller
		cout << "please enter the fidback you want to give to the seller (max 100 letters)" << endl;
		cleanBuffer();
		cin.getline(fidback, maxFidbackLen);
		// insert the fidback to the seller //
		GiveFidbackToSeller(AllSellers[position] , fidback);
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
	cleanBuffer();
	cin.getline(username,maxLen);
	cout << "Enter Password (Max 30 chars) :" << endl;
    cin.getline(password,maxLen);
	cout << "Enter Country,press enter and then a City (Max 30 chars per location)  :" << endl;
	cin.getline(country, maxLen);
	cin.getline(city, maxLen);
	cout << "Enter Street,press enter and then Homenumber :" << endl;
	cin.getline(street, maxLen);
	cin >> homenumber;

	if (Choice == 1) // need to add buyer.
	{
		int i = 0;
		Buyer* newBuyer = new Buyer(fname, lname, username, password, country, city, street, homenumber);
		Buyer** temp = new Buyer*[TotalBuyerslogSize + 1];
		for (i = 0; i < TotalBuyerslogSize; i++)
		{
			temp[i] = (*AllBuyers)[i];
		}

		temp[i] = newBuyer;
		delete[] * AllBuyers;
		*AllBuyers = temp;
		TotalBuyerslogSize++;
	}
	else // meaning we need to add seller
	{
			int i = 0;
			Seller* newSeller = new Seller(fname, lname, username, password, country, city, street, homenumber);
			Seller** temp = new Seller*[TotalSellerslogSize + 1];
		for ( i = 0; i < TotalSellerslogSize; i++)
		{
			temp[i] = (*AllSellers)[i];
		}
	
		temp[i] = newSeller;
		delete[]  *AllSellers;
		*AllSellers = temp;  // AllSeller is now temp //
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




void addItem(Seller** Sellers, int& size)
{
	char username[maxLen], password[maxLen];
	cout << " Please log in to the system in order to add an item to your merchandise" << endl;
	cout << "Please enter your username: " << endl;
	cin.getline(username, maxLen);
	cout << "Please enter your password: " << endl;
	cin.getline(password, maxLen);

	for (int i = 0; i < size; i++) // send to a function in the future //
	{
		if (strcmp((Sellers)[i]->getUsername(), username) == 0 && strcmp((Sellers)[i]->getPassword() , password) == 0) // search for the seller in the system
		{
			cout << "login successful! Welcome " << username <<"!" << endl;
			AddtoSeller(Sellers[i], i); // After we found our seller in the system, we need to add the item.
			return;
		}
	}
	cout << "Unsuccessful login! Wrong username or password" << endl;
	return;

}

void AddtoSeller(Seller* SellerToAdd, int& position) 
{		// recieves the sellers array and the index of which specific seller is located in the array.
	int Category, price;
	char ItemName[ItemNameMAXlen];
	cout << "Please Select your item category that you want to add: " << endl;
	for (int i = 0; i < TotalCategories; i++)
		cout << i << " - " << Categories[i] << endl; // prints all the categories to the console //

	cin >> Category;
	cout << "Enter your item name (max of 50 chars):" << endl;
	cleanBuffer();
	cin.getline(ItemName, ItemNameMAXlen);
	cout << "Enter the price of your item :" << endl;
	cin >> price;

	Item* item = new Item(ItemName, price,Category); // Make a new item from the data we got about it.
	addItemToSeller(SellerToAdd, position, item);
}

void addItemToSeller(Seller* TheSeller, int& index,Item* item )
{

	TheSeller->AddItemToStock(*item,item->getItemCategory()); // Add the item to the seller's merch

}



