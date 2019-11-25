

#pragma once
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
class Address
{
private:
	char* country;
	char* city;

public:

	Address(char* Country,char* City);
	~Address();
	void setCountry(char* country);
	void setCity(char* city);
	char* getCountry();
	char* getCity();
};