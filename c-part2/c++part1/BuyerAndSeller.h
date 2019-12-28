#pragma once
#include "buyer.h"
#include "Seller.h"
#include "User.h"



class BuyerAndSeller : public Buyer, public Seller 
{

public:
	BuyerAndSeller(char* username, char* firstname, char* lastname, char* password,
		char* Country, char* City, char* Street, int& HomeNumber);


};