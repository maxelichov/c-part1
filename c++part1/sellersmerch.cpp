



#include "sellersmerch.h"
#include "pch.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Seller.h"
#pragma warning(disable: 4996)
using namespace std;





//////////////////////////////////////////////////////////////////////////


// ITEMS //

Item ::Item( char* name, int price,char* serialNumber , eCategory itemCategory)// ctor //
{
	setItemName(name);
	setItemPrice(price);
	setItemSerialNumber(serialNumber);
	setCategory(itemCategory);


}




Item ::~Item()// dtor//
{
	 // need to delete the item from the sellers stock //
	// when item is sold to a buyer we need delete from sellers stock and add to buyer //
	delete[] ItemName;
	ItemName = nullptr;
	delete[] ItemSerialNumber;
	ItemSerialNumber = nullptr; // no deletion beacuse item goes to the buyer // /*to do!*/

}

 bool Item :: setItemName(const char* name) 
{
	 if (ItemName != nullptr) {
		 delete ItemName;
	 }
	 // item name can include letters and digits so need to think ..... //
	 ItemName = strdup(name);
	 return true;
}

bool Item:: setItemPrice(int price)
{
	 // only problem is if price is equal to zero or negative number //
	if (price <= 0)
	{
		cout << "invalid price" << endl;
		return 0;
	}
	ItemPrice = price;
	return true;
}


bool Item::setItemSerialNumber(char* serialNumber)
{
	int len = strlen(serialNumber);
	if (len < 1) {
		cout << "Invalid serial number" << endl;
		return false;
	}
	if (ItemSerialNumber != nullptr) {
		delete ItemSerialNumber;
	}
	ItemSerialNumber = strdup(serialNumber);
	return true;
}

/*bool Seller ::CheckSellerItemStock(Seller& seller)
{
	
}*/

bool Item:: setCategory(eCategory newCategory)
{
	int index = newCategory;
	if (index >= 0 && index <= 4)
	{
	    itemCategory = newCategory;
		return true;
	}
	cout << "Invalid Category " << endl;
	return false;
}


char* Item::getItemName()
{
	return ItemName;
}

int	Item:: getItemPrice()
{

	return ItemPrice;
}
char* Item:: getItemSerialNumber()
{
	return ItemSerialNumber;

}

  int  Item::getItemCategory() 
{
	int index = (int)itemCategory;					/////need to fix ///////
	return  index;
}

/////////////////////////////////////////////// Item Node

  /*
  ItemNode::~ItemNode()
  {
	  delete item;
	  item = nullptr;
  }*/


void ItemList::insert(Item& item) {
	/*
	Check if item (serial number) already exists
	*/
	
	ItemNode* newItem = new ItemNode(item);
	newItem->next = nullptr;
	if (head == nullptr)
	{
		head = newItem;
	}
	if (tail == nullptr)
	{
		tail = newItem;
	}
	else
	{
			/*need to fix*/		//insert to head of list // 
		ItemNode* temp = head;
		newItem->next = temp->next;
		head = newItem;
		
	
	}
}

ItemList::~ItemList()
{
	delete head;
}

Department::Department(eCategory cat)
{
	department = cat;
	stock = new ItemList();
}

void Department::addItem(Item& item)
{
	stock->insert(item);
}

Department::~Department()
{
	delete stock;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
							//////////// Merchandise//////////////////////////////

 Merchandise::Merchandise(int NumOfDepartment , int TotalNumOfItems )
 {
	 	// allocate 4 Departments //
		
	 Departments = new Item*[4];
	 
	 
 }

 /*Merchandise :: ~Merchandise()
 {
	


 }*/



 
