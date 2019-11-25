#include "pch.h"
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include "Address.h"
#include "buyer.h"
#include "Seller.h"
using namespace std;



const int maxLen  = 50;


int main()
{
	char country[7] = "israel", city[9] = "tel aviv",  lastname[8] = "elichov", password[6] = "12345";
	char firstname[4] = "max";
	char country2[maxLen] = "america", city2[maxLen] = "new york", f2name[maxLen] = "tomer", l2name[maxLen] = "shafir";
	char p2[maxLen] = "123";
	seller s1(firstname , lastname, password, country , city);
	seller s2(f2name, l2name, p2, country2, city2);
	return 0;
}
