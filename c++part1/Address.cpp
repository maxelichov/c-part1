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

void Address::setCountry(char* name)
{
	int len = strlen(name);

	country = new char[len + 1];
	strcpy(country, name);
	country = name;
	
}

void Address:: setCity(char* name)
{
	int len = strlen(name);
	city = new char[len + 1];
	strcpy(city, name);
	
}



char* Address::getCountry() 
{
	return country;
}
char* Address ::getCity() 
{
	return city;
}