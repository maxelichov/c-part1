#include "BuyerAndSeller.h"
using namespace std;
#include <iostream>


BuyerAndSeller::BuyerAndSeller(char* username, char* firstname, char* lastname, char* password,
	char* Country, char* City, char* Street, int& HomeNumber) : User(username, firstname, lastname, password,
		Country, City, Street, HomeNumber), Buyer(), Seller()
{


}