
#pragma once
#include "Address.h"
#include "Merchandise.h"
#include "feedback.h"
class ItemNode;

class Seller
{
private:
	char* s_Firstname;
	char* s_Lastname;
	char* s_Password;
	char* s_Username;
	Address s_address;
	Merchandise s_Merch;
	Feedback allFeedBacks;  


public:

	Seller(char* s_Firstname, char* s_Lastname, char* s_Username, char* s_Password, char* Country, char* City, char* Street, int& HomeNumber);
	~Seller();											 /*d'tor*/
	bool setName(char* Firstname, char* Lastname);
	bool setUsername(char* Username);
	bool setPassword(char* Password);
	char* getUsername() const;
	char* getPassword() const;
	void s_show()   const;
	void AddItemToStock(Item& NewItem,int Category); 
	void addFeedback(char* feedback,char* BuyerName);
	int getCategoriesSize();
	bool HaveCategory(const char* Category);
	void showCategoryItems(const char* Category);
	Item* getItem(const char* Category,const char* ItemName);

	
	/*bool CheckSellerItemStock(Seller& seller);*/
	/*friend GiveFidbackToSeller(Seller* TheSeller, char* feedback);*/ //Todo


};





