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
enum eCategory { Children, Clothing, Electricity, Office };
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
bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password, int& index);
bool IfPurchasedFrom(char* TheSeller, Buyer* TheBuyer);
//bool checkIfPurchasedFrom(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize, char* SellerName,
//	char* username);
void GiveFeedbackToSeller(char* feedback, Buyer* TheBuyer, char* SellerName);
void FindAndAddItem(const int& CategoryChoice, Buyer* TheBuyer, Seller** AllSellers, int Sellers_sz);
void addItemtobuyer(Buyer** AllBuyers, Seller** AllSellers, const int& TotalBuyerslogSize, const int& TotalSellerslogSize);
bool ValidateCategory(int choice);
void AddItemtobuyerFINAL(Buyer* TheBuyer, Seller** AllSellers, int& Sellers_sz, char* TheSeller, char* TheItem, const char* Category);
void InsertToBuyersCart(Buyer* TheBuyer, Seller* TheSeller, Item* item);



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
	case 5:
		addItemtobuyer(*AllBuyers, *AllSellers, TotalBuyersLogSize, TotalSellerslogSize);
		break;
	case 6:
		/*MakeAPurchase()*/

		default:
			break;
	}
}

/*void MakePurchase()
{

}*/

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

void PurchasedFrom(Buyer* TheBuyer)
{
	cout << "sellers you purchased from are : " << endl;
	

}

void addFeedback(Buyer** AllBuyers, Seller** AllSellers, int& TotalSellerslogSize, int& TotalBuyerslogSize)
{	/*need to login as buyer before adding a feedback*/
	char username[maxLen], password[maxLen];
	int indexOfBuyer;
	cout << " Please log in to the system in order to add a feedback to a seller" << endl;
	cout << "Please enter your username: " << endl;
	cin.getline(username, maxLen); //PROBLEM WITH THE ENTER. CURRENTLY NEED TO PRESS ENTER TWICW.
	cout << "Please enter your password: " << endl;
	cin.getline(password, maxLen);

	bool Valid = IsBuyerInSystem(AllBuyers, TotalBuyerslogSize, username, password,indexOfBuyer);
	if (!Valid)
	{
		cout << "Error: Buyer " << username << " Is not in the system with the password " << password << endl;
		return;
	}

	cout << "Welcome " << username << endl;

	char feedback[maxFeedbackLen];
	char SellerName[maxLen];
	
	if (AllBuyers[indexOfBuyer]->getPurchasedFromSz() != 0) // check if there were any purchases
	{
		cout << "please enter the username of the seller you wish to give a feedback to " << endl;
		AllBuyers[indexOfBuyer]->showPurchasedFrom(); 
		cin.getline(SellerName, maxLen);



		bool found = IfPurchasedFrom(SellerName, AllBuyers[indexOfBuyer]);
		if (!found)
		{
			cout << "the name you enterd does not exist in the system. please try again." << endl;
			return;
		}

		

		cout << "Please enter the feedback you want to give to the seller (max 100 letters)" << endl;
		/*cleanBuffer();//NEED TO FIX. SOMETHING WITH THE cleanBuffer().*/
		cin.getline(feedback, maxFeedbackLen);
		GiveFeedbackToSeller(feedback, AllBuyers[indexOfBuyer],SellerName);
	}
	else
		cout << "in order to place a feedback to a seller , you need to purchase from the seller first " << endl;


}



void addItemtobuyer(Buyer** AllBuyers, Seller** AllSellers, const int& TotalBuyerslogSize, const int& TotalSellerslogSize)
{
	if (TotalSellerslogSize == 0) // no sellers in the system, can't add any item
	{
		cout << "No available sellers in the system" << endl;
		return;
	}

	int CategoryChoice, BuyerIndex;
	bool res;
	/*need to login as buyer before adding a feedback*/
	char username[maxLen], password[maxLen];
	cout << " Please log in to the system in order to add an item to your cart" << endl;
	cout << "Please enter your username: " << endl;
	cin.getline(username, maxLen);
	cout << "Please enter your password: " << endl;
	cin.getline(password, maxLen);
	
	bool Valid = IsBuyerInSystem(AllBuyers, TotalBuyerslogSize, username, password,BuyerIndex);
	if (!Valid)
	{
		cout << "Error: Buyer " << username << " is not in the system with the password " << password << endl;
		return;
	}

	cout << "Welcome " << username << endl << "Pick a category: " << endl;
	for (int i = 0; i < TotalCategories; i++)
		cout << i << " - " << Categories[i] << endl; // prints all the categories to the console //

	cin >> CategoryChoice;
	res = ValidateCategory(CategoryChoice);
	while (!res)
	{
		cout << "Invalid category choice" << endl;
		cin >> CategoryChoice;
		res = ValidateCategory(CategoryChoice);
	}

	FindAndAddItem(CategoryChoice, AllBuyers[BuyerIndex], AllSellers, TotalSellerslogSize);

}

void FindAndAddItem(const int& CategoryChoice, Buyer* TheBuyer, Seller** AllSellers, int Sellers_sz)
{
	char Sellername[maxLen];
	char ItemName[ItemNameMAXlen];
	int val;
	for (int i = 0; i < Sellers_sz; i++) // run on all sellers
	{ 
	    if (AllSellers[i]->HaveCategory(Categories[CategoryChoice])) // If the seller have the requested category
		{
			cout << "Items of seller: " << AllSellers[i]->getUsername() << endl;
			AllSellers[i]->showCategoryItems(Categories[CategoryChoice]); // show all the items that the seller have in the category
		}
	}
	cout << "To exit press 1, to continue purchase press 2 and enter" << endl;
	cin >> val;
	////// NEED TO FIX
	while (!((val == 1) || (val == 2)))
	{
		cout << " Please enter ""1"" to exit or ""2"" to continue" << endl;
		cin.clear();
		cin.ignore(123, '\n');
		cin >> val;
	}
	if (val == 1)
		return;
	else
	{
		cout << endl << "For adding an item to your cart please enter seller's name and item name: \n Seller name:";
		cleanBuffer();
		cin.getline(Sellername, maxLen);
		cout << "Item name: " << endl;
		cin.getline(ItemName, ItemNameMAXlen);
	}

	AddItemtobuyerFINAL(TheBuyer, AllSellers, Sellers_sz, Sellername, ItemName, Categories[CategoryChoice]);

}

void AddItemtobuyerFINAL(Buyer* TheBuyer, Seller** AllSellers, int& Sellers_sz, char* TheSeller, char* TheItem, const char* Category)
{
	int i;
	Item* item = nullptr;
	for (i = 0; i < Sellers_sz; i++) // run on all sellers
	{
		if (strcmp(AllSellers[i]->getUsername(), TheSeller) == 0) // If the seller matches the name
		{
			if (AllSellers[i]->HaveCategory(Category)) // If the seller really have the category that the buyer looked for
			{
				item = AllSellers[i]->getItem(Category, TheItem);
				break;

			}
		} 
	}
	if (item != nullptr) // meaning we found the item of choice.
	{
		InsertToBuyersCart(TheBuyer, AllSellers[i], item); // i = 1  , and AllSellers[1] is not initilized.
	}


}



void InsertToBuyersCart(Buyer* TheBuyer, Seller* TheSeller, Item* item) // were recieving UNINITIAZLIZED SELLER!!//
// try sending the adress of AllSellers[i].
{
	TheBuyer->InsertItem(item);
	TheBuyer->UpdatePurchasedFromArr(TheSeller);
}

bool ValidateCategory(int choice)
{
	if (choice >= 0 && choice <= 3)
		return true;

	return false;
}

bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password,int& index)
{
	for (int i = 0; i < TotalBuyersLogSize; i++) // send to a function in the future //
	{
		if (strcmp((Buyers)[i]->getUsername(), username) == 0 && strcmp((Buyers)[i]->getPassword(), password) == 0) // search for the buyer in the system
		{
			index = i;
			return true;
		}
	}
	return false;
}



bool IfPurchasedFrom(char* TheSeller, Buyer* TheBuyer)
{
		if (TheBuyer->getSeller(TheSeller))// search for the seller in the buyers purchased from array.
			return true;
	
	return false;
}

//bool checkIfPurchasedFrom(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize, char* SellerName,
//	                      char* username)
//{
//	int i, j;
//	for (i = 0; i < TotalBuyerslogSize; i++)
//	{
//		if (strcmp((*AllBuyers)[i].getUsername(), username) == 0) // need to locate the buyer and check if he purchased from the seller
//		{
//			for (j = 0; j < (*AllBuyers)[i].getPurchasedFromSz(); j++)
//			{
//				if (strcmp((*AllBuyers)[i].getSeller(j)->getUsername(), SellerName) == 0) // locate the seller in the buyer purchased from arr.
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}


void GiveFeedbackToSeller(char* feedback,Buyer* TheBuyer,char* SellerName) // friend fucntion of Seller obj? //
{
	(TheBuyer->getSeller(SellerName))->addFeedback(feedback, TheBuyer->getUsername()); // find the seller in the buyer purchased from arr and then add feedback to that seller
}


void cleanBuffer()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}