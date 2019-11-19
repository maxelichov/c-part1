#pragma once
#include "buyer.h"
#include "Address.h"
#include "shopingcart.h"

Buyer :: Buyer(char* name, Address& buyerAdress, char* bPassword) 
{
	setName(name);
	b_name = name;
	b_address = &buyerAdress;
	b_password = bPassword;

}

Buyer :: ~Buyer() /*d'tor*/
{
	delete[] b_name;
	delete[] b_password;
	b_address->~Address; 
	b_shopingCart;	/*need to create a shoping cart */
}


void Buyer:: setName(char* bName)
{

}

