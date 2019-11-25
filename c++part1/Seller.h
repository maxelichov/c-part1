#ifndef __Seller_H
#define __Seller_H

#include "Address.h"



class Seller
{
private:
	char* s_Firstname;
	char* s_Lastname;
	char* s_Password;
	char* s_Username;
	Address s_address;
	/*feedback allFeedBacks;*/ // to do//
	/*Item* allItems;*/

public:

	Seller(char* s_Firstname, char* s_Lastname, char* s_Username, char* s_Password, char* Country, char* City, char* Street, int& HomeNumber); //C'TOR
	~Seller();											 /*d'tor*/
	bool setName(char* Firstname, char* Lastname);
	bool setUsername(char* Username);
	bool setPassword(char* Password);
	void s_show()   const;


};





#endif // !__Seller_H

