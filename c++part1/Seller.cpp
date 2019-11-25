
#include "pch.h"
#pragma once
#define CRT_SECURE_NO_WARNINGS

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
	strcpy(l_name, lastname);
}
/*void seller :: setSellerAddress(Address& address)
{
	s_address = &address;
}*/

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

/* to get city and country use : s_address->getcity , s_address->getcountry*/
 

seller::seller(char* firstname, char* lastname, char* password, char* country, char* city) : s_address(country, city) 
{		/*ctor*/
	 setSellerFirstName(firstname);
	 setSellerLastName(lastname);
	 setSellerPassword(password);
	
}	

 seller :: ~seller() 
 {
	 /*dtor*/
	 delete[] f_name;
	 delete[] l_name;
	 delete[] s_password;
	 f_name = nullptr;
	 l_name = nullptr;
	 s_password = nullptr;
	/*city and country dying automaticaly in address dtor*/
 }


