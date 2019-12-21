#pragma once
#include "pch.h"
#include "Item.h"
#include <iostream>
#define TotalCategories 4
#pragma warning(disable : 4996)
using namespace std;
int Item::ItemSerialNumber;



Item::Item(char* name, int price,int category) : SerialNumber(++ItemSerialNumber)  // ctor //
{
	bool res;
	res = setItemName(name);
	do {
		if (!res)
		{
			cout << "Invalid item name please re-enter name(max 50 chars): " << endl;
			cin >> name;
			res = setItemName(name);
		}

	} while (!res);

	res = setItemPrice(price);
	do {
		if (!res)
		{
			cout << "Invalid price please re-enter price: " << endl;
			cin >> price;
			res = setItemPrice(price);
		}

	} while (!res);

	res = setCategory(category);
	do {
		if (!res)
		{
			cout << "Invalid category entered, please re-enter category: " << endl;
			cout << "0 - Children" << endl << "1 - Clothing" << endl << "2 - Electricity" << endl <<
				"3 - Office";

			cin >> category;
			res = setCategory(category);
		} 
	} while (!res);
}


Item ::~Item()// dtor//
{
	// need to delete the item from the sellers stock //
   // when item is sold to a buyer we need delete from sellers stock and add to buyer //
	delete[] ItemName;
	ItemName = nullptr;
}

bool Item::setItemName(const char* name)
{
	int length = strlen(name);
	if (length < 1 || length > ItemNameMAXlen)
		return false;

	ItemName = new char[length+1];
	strcpy(ItemName, name);
	return true;
	
}

bool Item::setItemPrice(int price)
{
	// only problem is if price is equal to zero or negative number //
	if (price <= 0)
		return false;

	ItemPrice = price;
	return true;
}


bool Item::setCategory(int newCategory)
{ 
	if (newCategory >= 0 && newCategory <= 4)
	{
		itemCategory = (eCategory)newCategory;
		return true;
	}
	return false;
}


char* Item::getItemName() const
{
	return ItemName;
}

int	Item::getItemPrice() const
{

	return ItemPrice;
}
int Item::getItemSerialNumber() const
{
	return SerialNumber;
}

int  Item::getItemCategory() const
{		
	return  (int)itemCategory;
}

void Item::showTheItem() const
{
	cout << "Item Name: " << ItemName << ", Price: " << ItemPrice << ", Serial Number:" << SerialNumber << endl;
	
}

Seller* Item::getSeller()
{
	return TheSeller;
}

void Item::setSeller(Seller* Seller)
{
	TheSeller = Seller;
}

bool Item::getStatus()
{
	return hasBeenBought;
}

void Item::setStatus(bool status)
{
	hasBeenBought = status;

}