

#pragma once



class Address
{
	char* Country;
	char* City;
	char* Street;
	int HomeNumber;
	Address(const Address& other); // prevent copy ctor.

public:
	Address(char* Country, char* City, char* Street, int& HomeNumber);
	bool setLocation(char* location, int flag);
	bool setHomeNumber(int homenumber);
	void show() const;
	~Address();

};


