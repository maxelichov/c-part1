#include "pch.h"
#include "buyer.h"
#include "Address.h"
#include "Shoppingcart.h"
#include <string.h>
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;


Buyer::Buyer(char* username, char* firstname, char* lastname, char* password,
	char* Country, char* City, char* Street, int& HomeNumber) : User(username, firstname,lastname,password,
		Country, City,Street,HomeNumber), b_Cart(), PurchasedFromArr(nullptr)
{
	


}


Buyer::~Buyer()
{
	delete[] PurchasedFromArr;
}

void Buyer::show() const
{
	cout << "Buyer name is: " << FirstName << " " << LastName << endl;
	cout << "Living in: ";
	showAddress();
	"Items in cart are:";
	ShowCart();
	cout << endl;
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