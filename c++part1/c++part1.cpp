

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
#include <string>
#include "c++part1.h"




// In order to log in as admin , username is "mta" and password is "1234"
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
		switch (MenuChoice)
		{
		case 1:
			SignIn(AllBuyers, AllSellers, TotalBuyerslogSize, TotalSellerslogSize);
			break;

		case 2:
		 	Register(&AllBuyers, TotalBuyerslogSize, TotalBuyersPhysSize, &AllSellers,
				TotalSellerslogSize, TotalSellersPhysSize);
			break;

		case 4:
			Adminlogin(AllBuyers,AllSellers,TotalBuyerslogSize,TotalSellerslogSize);
			break;

		default:
			break;

		}
	} while (MenuChoice != EXIT);
	cout << "Exiting Program";

	
	deleteSellers(AllSellers, TotalSellerslogSize);
	deleteBuyers(AllBuyers, TotalBuyerslogSize);
	
	return 1;
}

void displayMenu()
{
	cout << "Welcome! Please select your choice: \n1. Sign in \n2. Register \n3. Exit \n4. Admin login" << endl;
}
bool validateChoice(int& MenuChoice) // sending by ref for efficency //
{
	if (MenuChoice >= 1 && MenuChoice <= 4)
		return true;
	else
		return false;
}

void Register(Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize)
{
	int choice;
	cout << "\n Please select you choice: \n 1. Register as Buyer \n 2. Register as Seller \n ";
	 cin >> choice;

	 bool valid = validateRegisterMenu(choice);

		 if (!valid)
		 {
			 cout << "Wrong Input " << endl;
			 return;
		 }

		 RegisterMenu(choice,AllBuyers, TotalBuyersLogSize, TotalBuyersPhysSize,
			 AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
}

bool validateRegisterMenu(int& choice)
{
	if (choice < 1 || choice > 2)
		return false;

	return true;
}

void RegisterMenu(int& choice, Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize)
{
	switch (choice)
	{
	case 1: // Add buyer case
		addUser(AllBuyers, TotalBuyersLogSize, TotalBuyersPhysSize, choice, AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
		break;
	case 2: // Add seller case
		addUser(AllBuyers, TotalBuyersLogSize, TotalBuyersPhysSize, choice, AllSellers, TotalSellerslogSize, TotalSellersPhysSize);
		break;

	default:
		break;
	}
}



void SignIn(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize)
{
	char password[maxLen], username[maxLen];
	bool IsBuyer = false, IsSeller = false;
	int index;

	cout << "Please enter your username: \n";
	cin >> username;
	cout << "Please enter your password: \n";
	cin >> password;

	IsBuyer = IsBuyerInSystem(AllBuyers, TotalBuyerslogSize, username, password, index);
	if (IsBuyer)
	{
		caseBuyer(AllBuyers[index], AllSellers, TotalSellerslogSize);

	}
	else if(IsSeller = IsSellerInSystem(AllSellers, TotalSellerslogSize, username, password, index))
	{
		caseSeller(AllSellers[index]);
	}

	if (IsBuyer == false && IsSeller == false)
	{
		cout << "Username or password is incorrect" << endl;

	}
}

void displayBuyerMenu(Buyer* TheBuyer)
{
	cout << "\nWelcome " << TheBuyer->getUsername() << "!" << endl;
	cout << "Please select your choice from the menu: " << endl;
	cout << "1. Add feedback to a seller \n2. Add an item to your cart \n3. Make an order \n4. My Cart" <<
           "\n5. Return to main menu" << endl;
}

 void displaySellerMenu(Seller* TheSeller)
{
	 cout << "Welcome " << TheSeller->getUsername() << "!" << endl;
	 cout << "Please select your choice from the menu: " << endl;
	 cout << "1. Add an item to your stock \n2. Show all the current items in your stock"
		 "\n3. Return to main menu" << endl;
}
void caseSeller(Seller* TheSeller)
{
	int choice;
	do {
		displaySellerMenu(TheSeller);
		cin >> choice;
		switch (choice)
		{
		case 1:
			AddtoSeller(TheSeller);
			break;

		case 2:
			ShowStock(TheSeller);
			break;

		default:
			break;

		}

	} while (choice != EXIT);
}

void ShowStock(Seller* TheSeller)
{
	TheSeller->ShowStock();
}

void caseBuyer(Buyer* TheBuyer, Seller** AllSellers, int& TotalSellerslogSize)
{
	int choice;
	do {
		displayBuyerMenu(TheBuyer);
		cin >> choice;
		switch (choice)
		{
		case 1: // add feedback to seller
			addFeedback(TheBuyer); // TODO
			break;
		case 2: // add an item to cart
			addItemtobuyer(TheBuyer, AllSellers, TotalSellerslogSize);
			break;

		case 3: // make an order of items from your cart
			MakeAPurchase(TheBuyer);
			break;

		case 4:
			ShowMerch(TheBuyer);
			break;

		default:
			break;

		}


	} while (choice != ExitBuyerMenu);
	
}

void ShowMerch(Buyer* TheBuyer)
{
	cout << endl;
	TheBuyer->ShowCart();
	cout << "Total Price is: " << TheBuyer->getPriceOfCart();
}

void MakeAPurchase(Buyer* TheBuyer)
{
	if (TheBuyer->getTotalItems() == 0)
	{
		cout << "Error: Your cart is empty " << endl;
		return;
	}
	cout << "All the items in your cart are: " << endl;
	TheBuyer->ShowCart();
	cout << "\nThe total price of your cart is: " << TheBuyer->getPriceOfCart() << endl;
	cout << "to purchase all the items in your cart press 1" << endl;
	cout << "to purchase some items from you cart press 2" << endl;
	int Purchase;
	cin >> Purchase;
	if(Purchase == 1)
	{
		cout << "You have payed: " << TheBuyer->getPriceOfCart() << endl;
		cout << "Thank you for your purchase! the items are on their way to :\n";
		TheBuyer->UpdatePurchasedFromArr(TheBuyer->getCart());
		TheBuyer->showAddress();
		TheBuyer->resetCart(1); // 1 will be a flag, so we know to mark all the items 
		// that they were bought by making their in has been bought status to true.
	}
	else
	{
		ChooseCertainItemsFromCart(TheBuyer);
		
	}

	return;
}

void ChooseCertainItemsFromCart(Buyer* TheBuyer)
{
	ShoppingCart* newCart = new ShoppingCart();
	Item* Item;
	int TotalItems = 0;
	int serialNumber;
	char ItemName[ItemNameMAXlen];
	cout << "Write the item name you wish to add to your cart and serial number, or to finish process enter -1" << endl;
	cout << "Enter item name or ""-1"" to finish process: ";
	cleanBuffer();
	cin.getline(ItemName, ItemNameMAXlen);
	while (!(strcmp(ItemName, "-1") == 0)) // run untill user enters -1;
	{
		cout << "Enter item serial number or ""-1"" to finish process: ";
		cin >> serialNumber;
		if (serialNumber == -1)
			break;

		Item = TheBuyer->getItemFromCart(serialNumber);
		if (Item != nullptr) // if the item with name and serial number exists in the current cart of buyer
		{
			if (strcmp(Item->getItemName(), ItemName) != 0)
			{
				cout << "The item name you entered" << ItemName << " dosen't have a matching serial number to: " << serialNumber;
				cout << "Please try again!\n";
				cout << "Enter item name or ""-1"" to exit: ";
				cleanBuffer();
				cin.getline(ItemName, ItemNameMAXlen);

			}
			else if (!(newCart->checkIfItemExists(*Item))) // if the item dosent exist then add him (prevent duplicates)
			{
				newCart->AddItemToCart(*Item); // add item to new cart
				TotalItems++;
				cout << "Enter another item name or ""-1"" to exit: ";
				cleanBuffer();
				cin.getline(ItemName, ItemNameMAXlen);
			}
			else
			{
				cout << "Item: " << Item->getItemName() << " already in your cart!" << endl;
				cout << "Please try again!" << endl;
				cout << "Enter another item name or ""-1"" to exit: ";
				cleanBuffer();
				cin.getline(ItemName, ItemNameMAXlen);
			}

		}
		else if (Item == nullptr)
		{
			cout << "Item " << ItemName << " with the serial number " << serialNumber << " wasn't found in your cart!" << endl;
			cout << "Please try again or enter -1 to finish the process" << endl;
			cout << "Enter item name or ""-1"" to exit: ";
			cleanBuffer();
			cin.getline(ItemName, ItemNameMAXlen);
		}

	}
	if (TotalItems)
	{
		cout << "\nYour new cart is: " << endl;
		newCart->ShowCart();
		cout << "Total price is: " << newCart->GetTotalPrice() << endl;
		TheBuyer->resetCart(0); // the 0 will be a flag, we need to check which items were bought so we can change their
		// has been bought status.
		TheBuyer->UpdateCart(newCart);
		TheBuyer->setTotalItems(TotalItems);
		cout << "To confirm purchase press 1, to go back to main menu press other key\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "You have payed: " << TheBuyer->getPriceOfCart() << endl;
			cout << "Thank you for your purchase! the items are on their way to :\n";
			TheBuyer->showAddress();
			TheBuyer->UpdatePurchasedFromArr(TheBuyer->getCart());
			TheBuyer->resetCart(1);
			
		}
		else
			TheBuyer->changeItemStatus(); // If left the menu without buying the new cart, mark all the items as not bought.
	}
}

void MakePurchase(Buyer)
{
	cout << "choose the item you wish to buy from the shopping cart" << endl;

}

void addUser(Buyer*** AllBuyers, int& TotalBuyerslogSize, int& TotalBuyersPhysSize, int& Choice, Seller*** AllSellers, int& TotalSellerslogSize,
	int& TotalSellersPhysSize) // function for both to add buyer and seller instead of 2 funcs.
{
	char fname[maxLen], lname[maxLen], password[maxLen], username[maxLen], country[maxLen],
		city[maxLen], street[maxLen];
	int homenumber;
	if(Choice == 1)
	cout << "Please fill out our form in order to make a new Buyer :" << endl;
	else if(Choice == 2)
	cout << "Please fill out our form in order to make a new Seller :" << endl;
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
		bool Existed = false;
		int i = 0;
		Buyer* newBuyer = new Buyer(fname, lname, username, password, country, city, street, homenumber);
		while (UsernameExists(*AllBuyers, TotalBuyerslogSize,*AllSellers,TotalSellerslogSize, username))
		{
	        
			delete newBuyer;
			cout << endl << "The username " << username << " is already taken! please try again" << endl;
			cout << "Enter new username: ";
			if(!Existed)
			   cleanBuffer();

			cin.getline(username, maxLen);
			newBuyer = new Buyer(fname, lname, username, password, country, city, street, homenumber);
			Existed = true;
		}

		cout << "\nSuccess in making a buyer" << endl;
		Buyer** temp = new Buyer * [TotalBuyerslogSize + 1]; // make new buyer array with more room
		for (i = 0; i < TotalBuyerslogSize; i++) // copy all the old buyers to the new array
			temp[i] = (*AllBuyers)[i];

		temp[i] = newBuyer; // put the new buyer into the array
		delete[] *AllBuyers;
		*AllBuyers = temp;
		TotalBuyerslogSize++;
	}
	else // meaning we need to add seller
	{
		bool Existed = false;
		int i = 0;
		Seller* newSeller = new Seller(fname, lname, username, password, country, city, street, homenumber);
		while (UsernameExists(*AllBuyers, TotalBuyerslogSize, *AllSellers, TotalSellerslogSize, username))
		{
			delete newSeller;
			cout << endl << "The username " << username << " is already taken! please try again" << endl;
			if(!Existed)
			 cleanBuffer();
			cin.getline(username, maxLen);
			newSeller = new Seller(fname, lname, username, password, country, city, street, homenumber);
			Existed = true;
		}

		cout << "Success in making a seller" << endl;
		Seller** temp = new Seller * [TotalSellerslogSize + 1];
		for (i = 0; i < TotalSellerslogSize; i++)
			temp[i] = (*AllSellers)[i];

		temp[i] = newSeller;
		delete[] * AllSellers;
		*AllSellers = temp;  // AllSeller is now temp //
		TotalSellerslogSize++;
	}
}


bool IsSellerInSystem(Seller** Sellers, const int& TotalSellerslogSize, char* username, char* password,int& index)
{
	for (int i = 0; i < TotalSellerslogSize; i++)
	{
		if (strcmp((Sellers)[i]->getUsername(), username) == 0 && strcmp((Sellers)[i]->getPassword(), password) == 0) // search for the seller in the system
		{
			index = i;
			return true;
		}
	}
	return false;
}

void AddtoSeller(Seller* SellerToAdd)
{	
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
	addItemToSeller(SellerToAdd,  item);
}

void addItemToSeller(Seller* TheSeller,  Item* item)
{
	TheSeller->AddItemToStock(*item, item->getItemCategory()); // Add the item to the seller's merch
	cout << "Item added to your stock!" << endl;
}

void PurchasedFrom(Buyer* TheBuyer)
{
	cout << "Sellers you purchased from are: " << endl;
}

void addFeedback(Buyer* TheBuyer)
{	

	char feedback[maxFeedbackLen];
	char SellerName[maxLen];
	
	if (TheBuyer->getPurchasedFromSz() != 0) // check if there were any purchases
	{
		cout << "please enter the username of the seller you wish to give a feedback to " << endl;
		TheBuyer->showPurchasedFrom(); 
		cleanBuffer();
		cin.getline(SellerName, maxLen);


		bool found = IfPurchasedFrom(SellerName, TheBuyer);
		if (!found)
		{
			cout << "the name you enterd does not exist in the system. please try again." << endl;
			return;
		}

		cout << "Please enter the feedback you want to give to the seller (max 100 letters)" << endl;
		cin.getline(feedback, maxFeedbackLen);
		GiveFeedbackToSeller(feedback, TheBuyer,SellerName);
	}
	else
		cout << "in order to place a feedback to a seller , you need to purchase from the seller first " << endl;


}



void addItemtobuyer(Buyer* TheBuyer, Seller** AllSellers, const int& TotalSellerslogSize)
{
	if (TotalSellerslogSize == 0) // no sellers in the system, can't add any item
	{
		cout << "No available sellers in the system" << endl;
		return;
	}

	int CategoryChoice;
	bool res;


	cout << "Pick a category: " << endl;
	for (int i = 0; i < TotalCategories; i++)
		cout << i << " - " << Categories[i] << endl;// prints all the categories to the console //

	cin >> CategoryChoice;
	res = ValidateCategory(CategoryChoice);
	while (!res)
	{
		cout << "Invalid category choice" << endl;
		cin >> CategoryChoice;
		res = ValidateCategory(CategoryChoice);
	}

	FindAndAddItem(CategoryChoice, TheBuyer, AllSellers, TotalSellerslogSize);

}

void FindAndAddItem(const int& CategoryChoice, Buyer* TheBuyer, Seller** AllSellers, int Sellers_sz)
{
	bool AtleastOneItem = false;
	char Sellername[maxLen];
	int serialNumber;
	int val;
	for (int i = 0; i < Sellers_sz; i++) // run on all sellers
	{ 
	    if (AllSellers[i]->HaveCategory(Categories[CategoryChoice])) // If the seller have the requested category
		{
			AtleastOneItem = true;
			cout << "Items of seller: " << AllSellers[i]->getUsername() << endl;
			AllSellers[i]->showCategoryItems(Categories[CategoryChoice]); // show all the items that the seller have in the category
			cout << endl;
		}
	}
	if (AtleastOneItem == false)
	{
		cout << "Error: No items available in the category you picked!" << endl;
		return;
	}
	cout << "To exit press 1, to continue purchase press 2 and enter" << endl;
	cin >> val;
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
		cout << endl << "For adding an item to your cart please enter seller's name ," <<
			" and serial number of item: \nSeller name:";
		cleanBuffer();
		cin.getline(Sellername, maxLen);
		cout << "Item serial number: ";
		cin >> serialNumber;
	}

	AddItemtobuyerFINAL(TheBuyer, AllSellers, Sellers_sz, Sellername, serialNumber, Categories[CategoryChoice]);

}

void AddItemtobuyerFINAL(Buyer* TheBuyer, Seller** AllSellers, int& Sellers_sz, char* TheSeller, int& SerialNumber, const char* Category)
{
	int i;
	Item* item = nullptr;
	for (i = 0; i < Sellers_sz; i++) // run on all sellers
	{
		if (strcmp(AllSellers[i]->getUsername(), TheSeller) == 0) // If the seller matches the name
		{
			if (AllSellers[i]->HaveCategory(Category)) // If the seller really have the category that the buyer looked for
			{
				item = AllSellers[i]->getItem(Category, SerialNumber);
				break;

			}
		} 
	}
	if (item != nullptr) // meaning we found the item of choice.
		InsertToBuyersCart(TheBuyer, AllSellers[i], item);

}

void InsertToBuyersCart(Buyer* TheBuyer, Seller* TheSeller, Item* item) // put the item into the buyers cart
{
	if (TheBuyer->InsertItem(item))
	{
		TheBuyer->IncreaseTotalItems(); // increase the total items by 1;
		cout << "Item has been added to your cart!" << endl;
	}
}

bool ValidateCategory(int& choice)
{
	if (choice >= 0 && choice <= 3)
		return true;

	return false;
}

bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password,int& index)
{


	for (int i = 0; i < TotalBuyersLogSize; i++) 
	{
		if (strcmp((Buyers)[i]->getUsername(), username) == 0 && strcmp((Buyers)[i]->getPassword(), password) == 0) // search for the buyer in the system
		{
			index = i; // update index by ref
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

void deleteSellers(Seller** AllSellers, int& TotalSellerslogSize)
{
	for (int i = 0; i < TotalSellerslogSize; i++)
	{
		delete AllSellers[i];
	}
	delete[] AllSellers;
}

void deleteBuyers(Buyer** AllBuyers, int& TotalBuyerslogSize)
{
	for (int i = 0; i < TotalBuyerslogSize; i++)
	{
		delete AllBuyers[i];
	}

	delete[] AllBuyers;
}

void Adminlogin(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize)
{
	// Admin log in to the system for viewing details of all customers
	const char AdminName[] = "mta";
	const char AdminPass[] = "1234";

	char user[maxLen];
	char password[maxLen];

	cout << "Enter admin username: \n";
	cin.getline(user, maxLen);
	if (strcmp(user, AdminName) != 0)
	{
		cout << "Wrong username!" << endl;
		return;
	}
	cout << "Enter admin password: \n";
	cin.getline(password, maxLen);
	if (strcmp(password, AdminPass) != 0)
	{
		cout << "Wrong password!" << endl;
		return;
	}
	cout << "\nlogin successful!";
	displayAdminMenu(AllBuyers, AllSellers, TotalBuyerslogSize, TotalSellerslogSize);

}

void displayAdminMenu(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize)
{
	int choice;
	do
	{
		cout << "\nEnter your choice:\n1.Show all existing buyers \n2.Show all existing sellers \n3.Return to main menu\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			ShowAllBuyers(AllBuyers, TotalBuyerslogSize);
			break;

		case 2:
			ShowAllSellers(AllSellers, TotalSellerslogSize);
			break;

		default:
			break;

		}

	} while (choice != EXIT);
	cout << endl;
}

void ShowAllBuyers(Buyer** AllBuyers, int& size)
{
	for (int i = 0; i < size; i++)
		AllBuyers[i]->b_show();
}

void ShowAllSellers(Seller** AllSellers, int& size)
{
	for (int i = 0; i < size; i++)
		AllSellers[i]->s_show();
}

bool UsernameExists(Buyer** AllBuyers, int& TotalBuyerslogSize,Seller** AllSellers,int& TotalSellerslogSize, char* username)
{
	int i;
	for (i = 0; i < TotalBuyerslogSize; i++)
	{
		if (strcmp(AllBuyers[i]->getUsername(), username) == 0)
			return true;
	}

	for (i = 0; i < TotalSellerslogSize; i++)
	{
		if (strcmp(AllSellers[i]->getUsername(), username) == 0)
			return true;
	}

	return false;
}

void showSameItems(Seller** AllSellers, int TotalSellersLogSize)
{
	char itemName[maxLen];
	cout << "enter the name of the item you want to be displayed" << endl;
	cleanBuffer();
	cin.getline(itemName, maxLen);
	for (int i = 0; i < TotalSellersLogSize; i++)
	{
		Merchandise tempMerch = AllSellers[i]->getSellersMerchandise();
		int size = tempMerch.getNumOfDepartments();
		for (int j = 0; j < size; j++)
		{
			Department* currDep = tempMerch.getSpecificDepartment(j);
			currDep->
		}

		
	}
}
