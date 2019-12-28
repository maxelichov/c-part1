

#pragma once



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
	Address(const Address& other);

	const Address& operator=(const Address& other)
	{
		if (this != &other)
		{
			delete[] Country;
			delete[] City;
			delete[] Street;
			HomeNumber = other.HomeNumber;
			Country = strdup(other.Country);
			City = strdup(other.City);
			Street = strdup(other.Street);
		}
		return *this;
	}
	
	~Address();

};


