#include "Item.h"
#include <iostream>
using namespace std;


Item::Item(char* name, int price,int category) : SerialNumber(++ItemSerialNumber)  // ctor //
{
	setItemName(name);
	setItemPrice(price);
	setCategory(category);
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
	if (ItemName != nullptr) {
		delete ItemName;
	}
	// item name can include letters and digits so need to think ..... //
	ItemName = strdup(name);
	return true;
}

bool Item::setItemPrice(int price)
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


/*bool Seller ::CheckSellerItemStock(Seller& seller)
{

}*/

bool Item::setCategory(int newCategory)
{
	int index = newCategory;
	if (index >= 0 && index <= 4)
	{
		itemCategory = (eCategory)newCategory;
		return true;
	}
	cout << "Invalid Category " << endl;
	return false;
}


char* Item::getItemName()
{
	return ItemName;
}

int	Item::getItemPrice()
{

	return ItemPrice;
}
int Item::getItemSerialNumber()
{
	return SerialNumber;

}

int  Item::getItemCategory()
{
	int index = (int)itemCategory;					/////need to fix ///////
	return  index;
}