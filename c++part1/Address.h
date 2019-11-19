#pragma once

class Address
{
private:
	char* country;
	char* city;

public:

	Address(char* Country,char* City);
	bool setCountry(char* country);
	bool setCity(char* city);
	~Address();

};