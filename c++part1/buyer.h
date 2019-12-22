
#pragma once
#define maxLen 31
#include "Address.h"
#include "ShoppingCart.h"

class Item;
class Seller;

class Buyer
{ 
private:

	int TotalItemsIndex = 0;
	char* b_Firstname;
	char* b_Lastname;
	char* b_Username;
	char* b_Password;
	Address b_address;
	ShoppingCart b_Cart; // deafult when making a buyer will be null;
	Seller** PurchasedFromArr; // will point to all the sellers he purchased from.
	int PurchasedFrom_sz = 0; // size of the purchased from arr
	Buyer(const Buyer& other); // to deny copy of buyer. copy ctor is private.

public:

	Buyer(char* b_FirstName, char* b_LastName, char* b_Username, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber);
	bool setName(char* firstName, char* lastName);
	bool setUsername(char* username);
	bool setPassword(char* password);
	char* getUsername() const;
	char* getPassword() const;
	void showAddress() const;
	int getPurchasedFromSz () const;
	void b_show() const;
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



