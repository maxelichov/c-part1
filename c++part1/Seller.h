
#pragma once
#define CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


class seller
{
private:
	char* f_name; 
	char* l_name;
	char* s_password;
	Address s_address; 
	/*feedback allFeedBacks;*/ // to do//
	/*Item* allItems;*/

public:
	
	seller(char* firstname, char* lastname, char* password, char* country, char* city); /*need to make ctor for address */
	~seller();											 /*d'tor*/
	void setSellerFirstName(char* firstname);
	void setSellerLastName(char* lastname);
	void setSellerPassword(char* password);

public:

	char* getFirstName() const;
	char* getLastName() const;
	char* getPassword() const;
};


