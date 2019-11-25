
#pragma once
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define maxNameLen 26

class Address;
class Item;

class Buyer
{
private:

	int ItemIndex = 0;
	char *b_FirstName;
	char *b_LastName;
	Address* b_address;
	char* Password;
	Item** ShoppingCart; // Array of pointers to items

public:

	Buyer(char* b_FirstName, char* b_LastName, Address& buyerAdress, char* bPassword);
	bool setName(char* firstName, char* lastName);
	bool setPassword(char* password);
	/*bool setAddress(Address& UserAddress);*/
	~Buyer();


};



