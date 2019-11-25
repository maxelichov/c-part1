
#pragma once
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)




class seller
{
private:
	char* f_name; 
	char* l_name;
	Address* s_address; 
	char* s_password;
	/*feedback* allFeedBacks;*/ // to do//
	/*Item* allItems;*/

public:
	
	seller(char* firstname, char* lastname, char* password, Address& address); /*c'tor*/
	~seller();											 /*d'tor*/
	void setSellerFirstName(char* firstname);
	void setSellerLastName(char* lastname);
	void setSellerAddress(Address& address);
	void setSellerPassword(char* password);

public:

	char* getFirstName() const;
	char* getLastName() const;
	char* getCountry()   const;
	char* getCity() const;
	char* getPassword() const;
};


