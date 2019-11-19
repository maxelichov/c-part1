#include "Address.h"
#include <string.h>
#include "Buyer.h"
#include "Seller.h"
#include "shopingcart.h"

#define MAX_LEN 50

Address::Address(char* Country,char* City) /*copy c'tor*/
{
	country = new char[strlen(Country) + 1];
	country = Country;
	
	city = new char[strlen(City) + 1];
	city = City;

}
Address :: ~Address() /* d'tor*/
{
	delete[] country;
	country = nullptr;
	delete[] city;
	city = nullptr;
	
}

bool Address::setCountry(char* name)
{
	int len = strlen(name);
	if (len == 0 || len >= MAX_LEN)
		return 0;
	country = name;
	return 1;
}

bool Address::setCity(char* name)
{
	int len = strlen(name);
	if (len == 0 || len >= MAX_LEN)
		return 0;
	city = name;
	return 1;
}