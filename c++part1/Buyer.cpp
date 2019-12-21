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
			return false;
		}
	}

	for (i = 0; i < LNameLen; i++)
	{
		if (((lastName[i] < 'A') || (lastName[i] > 'Z')) && ((lastName[i] < 'a') || (lastName[i] > 'z')))
		{
			cout << "Invalid char in last name: " << lastName[i] << endl;
			return false;
		}
	}

	b_Firstname = strdup(firstName);
	b_Lastname = strdup(lastName);

	return true;
}

bool Buyer::setUsername(char* username)
{
	int len = strlen(username);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid username" << endl;
		return false;
	}

	b_Username = strdup(username);

	return true;

}

bool Buyer::setPassword(char* password)
{
	int len = strlen(password);
	if (len < 1 || len >= maxLen)
	{
		cout << "Invalid password" << endl;
		return false;
	}
	b_Password = strdup(password);

	return true;

}


Buyer::~Buyer()
{
	delete[] b_Firstname;
	delete[] b_Lastname;
	delete[] b_Password;
	delete[] b_Username;
	delete[] PurchasedFromArr;

}

void Buyer::b_show() const
{
	cout << "Buyer name is: " << b_Firstname << " " << b_Lastname << endl;
	cout << "Living in: ";
	b_address.show();
	"Items in cart are:";
	ShowCart();
	cout << endl;
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

void Buyer::ShowCart() const
{
	b_Cart.ShowCart();
}

int Buyer::getPriceOfCart()
{
	return b_Cart.GetTotalPrice();
}


bool Buyer:: InsertItem(Item* item)
{
	return (b_Cart.AddItemToCart(*item));
}

void Buyer::setTotalItems(int& size)
{
	TotalItemsIndex = size;

}

void Buyer::UpdateCart(ShoppingCart* newCart)
{
	b_Cart.updateCart(newCart);
}

int Buyer::getTotalItems()
{
	return TotalItemsIndex;
}

void Buyer::showAddress() const
{
	b_address.show();
}

Item* Buyer::getItemFromCart(int& ItemSerialNumber)
{
	return b_Cart.getItemFromCart(ItemSerialNumber);
}

void Buyer::UpdatePurchasedFromArr(ShoppingCart& Cart) 
{
	int Arr_sz = 0;
	ItemList* TheList = b_Cart.getCartList();
	Seller** SellersArr = TheList->getAllSellersFromList(Arr_sz); // after this we will have an array of all the sellers we have items from


	if (PurchasedFrom_sz == 0) //First purchase
	{
		PurchasedFromArr = new Seller * [Arr_sz];
		for(int i=0;i<Arr_sz;i++)
			PurchasedFromArr[i] = SellersArr[i];

		PurchasedFrom_sz = Arr_sz;
	}
	
	
	else // already purchased from at least one seller
	{
		int i;
		int NewSellers = 0;
		for (i = 0; i < Arr_sz; i++)
		{
			if (!(this->getSeller(SellersArr[i]->getUsername()))) // If the seller dosen't already appear in the PurchasedFrom arr.
				NewSellers++;
		}

		if (NewSellers > 0) // if there are new sellers that needed to be add.
		{
			Seller** temp = new Seller * [PurchasedFrom_sz + NewSellers]; // make room for all the new sellers

			for (i = 0; i < PurchasedFrom_sz; i++) // copy the old PurchasedFromArr to new arr.
				temp[i] = PurchasedFromArr[i];

			i = PurchasedFrom_sz;
			for (int j = 0; j < Arr_sz; j++) // copy the new sellers
			{
				if (!(this->getSeller(SellersArr[j]->getUsername())))
				{
					temp[i] = SellersArr[j];
					i++;
				}
			}
			delete[] PurchasedFromArr;
			PurchasedFromArr = temp;
			PurchasedFrom_sz += NewSellers;
		}
	}
}

void Buyer :: showPurchasedFrom()
{
	int purchasedFrom = this->getPurchasedFromSz();
	if (purchasedFrom == 0)
	{
		cout << "You havent purchased any items yet" << endl;
		
	}
	else
	{
		cout << "Sellers you purchased from are : " << endl;
		for (int i = 0; i < purchasedFrom; i++)
		{
			cout << i+1 <<" :" <<PurchasedFromArr[i]->getUsername() << endl;
		}
	}
}

void Buyer::resetCart(int flag)
{
	b_Cart.RemoveAllItems(flag);
	TotalItemsIndex = 0;
}

void Buyer::changeItemStatus()
{
	b_Cart.changeItemsStatus();
}

void Buyer::IncreaseTotalItems()
{
	TotalItemsIndex++;
}

void Buyer::DecreaseTotalItems()
{
	TotalItemsIndex--;
}

ShoppingCart& Buyer::getCart()
{
	return b_Cart;
}