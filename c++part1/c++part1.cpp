#pragma once
#include "pch.h"
#include "Item.h"
#include <iostream>
#include "Address.h"
#include "Buyer.h"
#include "Seller.h"
#include "Feedback.h"
#include "shoppingcart.h"
#include <stdio.h>
#include "Merchandise.h"
#include "ItemNode.h"

using namespace std;
#define maxFeedbackLen 100
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
void addFeedback(Buyer** AllBuyers, Seller** AllSellers, int& TotalSellerslogSize, int& TotalBuyerslogSize);
bool IsSellerInSystem(Seller** Sellers, const int& TotalSellerslogSize, char* username, char* password);
bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password);
bool IsSellerInSystemV2(Seller** Sellers, const int& TotalSellerslogSize, char* username,int& index);
bool checkIfPurchasedFrom(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize, char* SellerName,
	char* username);
void GiveFeedbackToSeller(Seller* TheSeller, char* feedback,char* username);


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
		break;
		case 4: // add feedback to seller
		addFeedback(*AllBuyers, *AllSellers , TotalSellerslogSize,TotalBuyersLogSize); // TODO
		break;

		default:
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
	cleanBuffer();
	cin.getline(username, maxLen);
	cout << "Enter Password (Max 30 chars) :" << endl;
	cin.getline(password, maxLen);
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
		Buyer** temp = new Buyer * [TotalBuyerslogSize + 1];
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
		Seller** temp = new Seller * [TotalSellerslogSize + 1];
		for (i = 0; i < TotalSellerslogSize; i++)
		{
			temp[i] = (*AllSellers)[i];
		}

		temp[i] = newSeller;
		delete[] * AllSellers;
		*AllSellers = temp;  // AllSeller is now temp //
		TotalSellerslogSize++;
	}
}

void addItem(Seller** Sellers, int& size)
{
	char username[maxLen], password[maxLen];
	cout << " Please log in to the system in order to add an item to your merchandise" << endl;
	cout << "Please enter your username: " << endl;
	cin.getline(username, maxLen);
	cout << "Please enter your password: " << endl;
	cin.getline(password, maxLen);

	bool Valid = IsSellerInSystem(Sellers, size, username, password);

	if (!Valid)
		cout << "Error: Seller " << username << " is not in the system with the password " << password << endl;

	return;
}

bool IsSellerInSystem(Seller** Sellers, const int& TotalSellerslogSize, char* username, char* password)
{
	for (int i = 0; i < TotalSellerslogSize; i++)
	{
		if (strcmp((Sellers)[i]->getUsername(), username) == 0 && strcmp((Sellers)[i]->getPassword(), password) == 0) // search for the seller in the system
		{
			cout << "login successful! Welcome " << username << "!" << endl;
			AddtoSeller(Sellers[i], i); // After we found our seller in the system, we need to add the item.
			return true;
		}
	}
	return false;
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

	Item* item = new Item(ItemName, price, Category); // Make a new item from the data we got about it.
	addItemToSeller(SellerToAdd, position, item);
}

void addItemToSeller(Seller* TheSeller, int& index, Item* item)
{
	TheSeller->AddItemToStock(*item, item->getItemCategory()); // Add the item to the seller's merch
}

void addFeedback(Buyer** AllBuyers, Seller** AllSellers, int& TotalSellerslogSize, int& TotalBuyerslogSize)
{	/*need to login as buyer before adding a feedback*/
	char username[maxLen], password[maxLen];
	cout << " Please log in to the system in order to add a feedback to a seller" << endl;
	cout << "Please enter your username: " << endl;
	cin.getline(username, maxLen);
	cout << "Please enter your password: " << endl;
	cin.getline(password, maxLen);

	bool Valid = IsBuyerInSystem(AllBuyers, TotalBuyerslogSize, username, password);
	if (!Valid)
	{
		cout << "Error: Buyer " << username << " Is not in the system with the password " << password << endl;
		return;
	}

	cout << "Welcome " << username << endl;

	char feedback[maxFeedbackLen];
	char SellerName[maxLen];
	int index;

	cout << "please enter the username of the seller you wish to give a feedback to " << endl;
	cin.getline(SellerName, maxLen);

	bool found = IsSellerInSystemV2(AllSellers, TotalSellerslogSize, SellerName,index);
	if (!found)
	{
		cout << "the name you enterd does not exist in the system. please try again." << endl;
		return;
	}

	bool ifPurchased = checkIfPurchasedFrom(AllBuyers, AllSellers, TotalBuyerslogSize, TotalSellerslogSize, SellerName,
		username); // need to check if buyer purchased from seller
	if (!ifPurchased)
	{
		cout << "Error: You didn't purchase item from the seller: " << SellerName << endl;
		return;
	}
		 
	cout << "Please enter the feedback you want to give to the seller (max 100 letters)" << endl;
	cleanBuffer();
	cin.getline(feedback, maxFeedbackLen);
	// insert the feedback to the seller //
	GiveFeedbackToSeller(AllSellers[index], feedback,username);
}

bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password)
{
	for (int i = 0; i < TotalBuyersLogSize; i++) // send to a function in the future //
	{
		if (strcmp((Buyers)[i]->getUsername(), username) == 0 && strcmp((Buyers)[i]->getPassword(), password) == 0) // search for the buyer in the system
			return true;
	}
	return false;
}

bool IsSellerInSystemV2(Seller** Sellers, const int& TotalSellerslogSize, char* username,int& index) // find the seller in the sellers array
{
	for (int i = 0; i < TotalSellerslogSize; i++)
	{
		if (strcmp((Sellers)[i]->getUsername(), username) == 0) // search for the seller in the system
		{
			index = i; // update index by ref so we can locate the seller in the array afterwards.
			return true;
		}
			
	}
	return false;
}

bool checkIfPurchasedFrom(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize, char* SellerName,
	                      char* username)
{
	int i, j;
	for (i = 0; i < TotalBuyerslogSize; i++)
	{
		if (strcmp((*AllBuyers)[i].getUsername(), username) == 0) // need to locate the buyer and check if he purchased from the seller
		{
			for (j = 0; j < (*AllBuyers)[i].getPurchasedFromSz(); j++)
			{
				if (strcmp((*AllBuyers)[i].getSeller(j)->getUsername(), SellerName) == 0) // locate the seller in the buyer purchased from arr.
				{
					return true;
				}
			}
		}
	}
	return false;
}

void GiveFeedbackToSeller(Seller* TheSeller , char* feedback,char* BuyerName) // friend fucntion of Seller obj? //
{
	TheSeller->addFeedback(feedback,BuyerName);
}


void cleanBuffer()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}