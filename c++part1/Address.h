

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
	bool setCountry(char* country);
	bool setCity(char* city);
	char* getCountry()	const;
	char* getCity() const;
	~Address();
};