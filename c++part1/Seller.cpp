
#include "pch.h"
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma once
#include "Address.h"
#include "Seller.h"
#include <string.h>
#include <iostream>
#include "Seller.h"



void seller :: setSellerFirstName(char* firstname)
{
	int nameLen = strlen(firstname);
	f_name = new char[nameLen + 1];
	strcpy(f_name, firstname);
}
void seller::setSellerLastName(char* lastname)
{
	int nameLen = strlen(lastname);
	l_name = new char[nameLen + 1];
	strcpy(f_name, lastname);
}
void seller :: setSellerAddress(Address& address)
{
	s_address = &address;
}

void seller :: setSellerPassword(char* password)
{
	int nameLen = strlen(password);
	s_password = new char[nameLen + 1];
	strcpy(s_password, password);
}

char* seller::getFirstName() const
{
	return f_name;
}
char* seller::getLastName() const
{
	return l_name;
}
char* seller :: getPassword() const
{
	return s_password;
}

char* seller :: getCountry() const
{
	Address::getCountry;					
}

char* seller :: getCity() const
{
	Address::getCity;
}

 seller ::seller(char* firstname, char* lastname, char* password, Address& address)
{
	 setSellerFirstName(firstname);
	 setSellerLastName(lastname);
	 setSellerPassword(password);
	 setSellerAddress(address);
}	

 seller :: ~seller()
 {
	 
	 delete[] f_name;
	 delete[] l_name;
	 delete[] s_password;
	 s_address->~Address; /*deletion of country and city is done in Address d'tor*/
 }


