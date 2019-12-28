
#pragma once
#define maxLen 31
#include "Address.h"
#include "ShoppingCart.h"
#include "User.h"

class Item;
class Seller;


class Buyer : virtual public User
{ 
private:

	int TotalItemsIndex = 0;
	ShoppingCart b_Cart; // deafult when making a buyer will be null;
	Seller** PurchasedFromArr; // will point to all the sellers he purchased from.
	int PurchasedFrom_sz = 0; // size of the purchased from arr

protected:
	/*Buyer();*/

public:

	Buyer(char* username, char* firstname, char* lastname, char* password,
		char* Country, char* City, char* Street, int& HomeNumber);
	virtual void show() const override; 
	int getPurchasedFromSz () const;
	Seller* getSeller(const char* Sellername);
	bool InsertItem(Item* item);
	void UpdatePurchasedFromArr(ShoppingCart& Cart);
	void showPurchasedFrom();
	void ShowCart() const;
	int getPriceOfCart();
	void resetCart(int flag);
	void IncreaseTotalItems();
	void DecreaseTotalItems();
	Item* getItemFromCart(int& ItemSerialNumber);
	void setTotalItems(int& size);;
	void UpdateCart(ShoppingCart* newCart);
	int getTotalItems();
	void changeItemStatus();
	ShoppingCart& getCart();



	~Buyer();

};



