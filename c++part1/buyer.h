
#pragma once
#define maxLen 31
#include "Address.h"

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
	Item** ShoppingCart = nullptr; // deafult when making a buyer will be null;
	Item** FinalCart = nullptr;
	Seller** PurchasedFromArr; // will point to all the sellers he purchased from.
	int PurchasedFrom_sz = 0; // size of the purchased from arr

public:

	Buyer(char* b_FirstName, char* b_LastName, char* b_Username, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber);
	/*Buyer(const Buyer& other);*/
	bool setName(char* firstName, char* lastName);
	bool setUsername(char* username);
	bool setPassword(char* password);
	char* getUsername() const;
	char* getPassword() const;
	int getPurchasedFromSz () const;
	void b_show() const;
	Seller* getSeller(int& index);


	~Buyer();

};



