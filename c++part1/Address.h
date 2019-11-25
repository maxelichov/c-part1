#pragma once
#ifndef __Address_H
#define __Address_H


class Address
{
	char* Country;
	char* City;
	char* Street;
	int HomeNumber;

public:
	Address(char* Country, char* City, char* Street, int& HomeNumber);
	bool setLocation(char* location, int flag);
	bool setHomeNumber(int homenumber);
	void show() const;
	~Address();

};


#endif // !__Adress_H
