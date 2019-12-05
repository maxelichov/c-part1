
#pragma once
#define maxLen 31
#include "Address.h"

class Item;

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

public:

	Buyer(char* b_FirstName, char* b_LastName, char* b_Username, char* bPassword, char* Country, char* City, char* Street, int& HomeNumber);
	/*Buyer(const Buyer& other);*/
	bool setName(char* firstName, char* lastName);
	bool setUsername(char* username);
	bool setPassword(char* password);
	void b_show() const;


	~Buyer();

};



