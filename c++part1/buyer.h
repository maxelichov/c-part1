#ifndef buyer.h
#define buyer.h
#pragma once
#include <iostream>
using namespace std;
#define maxLen 50

class feedback
{
private:
	Buyer* b_feedBack;
	char feedBackDescription[100];

};

class Buyer
{
private:

	char* b_name;
	Address* b_address;
	char* b_password;
	char** b_shopingCart;

public:
	
	Buyer(char* name , Address& buyerAdress , char* bPassword);
	~Buyer();
	void setName(char* bName);
	void setPassword(char* password);
	void setAddress(Address& UserAddress);
	

};




#endif // !"buyer.h"
