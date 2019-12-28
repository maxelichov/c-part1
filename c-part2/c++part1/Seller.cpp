#pragma once
#include "pch.h"
#include "Seller.h"
#include "Address.h"
#include <string.h>
#include <iostream>

#define maxLen 31
#pragma warning(disable: 4996)
using namespace std;


Seller::Seller(char* username, char* firstname, char* lastname, char* password,
	char* Country, char* City, char* Street, int& HomeNumber) : User(username, firstname, lastname, password,
		Country, City, Street, HomeNumber),  s_Merch(), allFeedBacks()
{								// seller ctor //																						// send to address ctor //			// send to merchandise ctor // //send to feedback ctor//


}


Seller::~Seller() // D'TOR
{


}

void Seller::show() const
{
	cout << "Seller's name is: " << FirstName << " " << LastName << endl;
	cout << "Living in: ";
	showAddress();
	cout << "Seller's stock is: " << endl;
	ShowStock();
	cout << endl;

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
