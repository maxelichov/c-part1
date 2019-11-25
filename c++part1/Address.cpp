#include "pch.h"
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include "Address.h"
#include <string.h>
#include "Buyer.h"
#include "Seller.h"

#define MAX_LEN 50

Address::Address(char* Country,char* City) /*copy c'tor*/
{
	setCountry(Country);
	setCity(City);

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
	country = new char[len + 1];
	strcpy(country, name);
	country = name;
	return 1;
}

bool Address:: setCity(char* name)
{
	int len = strlen(name);
	if (len == 0 || len >= MAX_LEN)
	return 0;
	city = new char[len + 1];
	strcpy(city, name);
	return 1;
}

Address :: ~Address()
{
	delete[] country;
	delete[] city;
	country = nullptr;
	city = nullptr;
	/*delete address itself?*/
}

char* Address::getCountry() const
{
	return country;
}
char* Address ::getCity() const
{
	return city;
}