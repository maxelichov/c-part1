
#pragma once
#include "Address.h"
#include "Merchandise.h"
#include "feedback.h"
#include "Item.h"
#include "User.h"

class ItemNode;

class Seller : virtual public User
{
private:
	Merchandise s_Merch;
	Feedback allFeedBacks;  
	Seller(const Seller& other); // to deny copy of seller . copy ctor is private.

protected:
	/*Seller();*/


public:

	Seller(char* username, char* firstname, char* lastname, char* password,
		char* Country, char* City, char* Street, int& HomeNumber);
	~Seller();										
	void ShowStock() const;
	virtual void show() const override;
	void AddItemToStock(Item& NewItem,int Category); 
	void addFeedback(char* feedback,char* BuyerName);
	int getCategoriesSize() const;
	bool HaveCategory(const char* Category);
	void showCategoryItems(const char* Category);
	void DisplayItemByName(const char* ItemName, int& counter);
	Item* getItem(const char* Category,int& SerialNumber);

	friend class Item;
	
	/*bool CheckSellerItemStock(Seller& seller);*/
	/*friend GiveFidbackToSeller(Seller* TheSeller, char* feedback);*/ //Todo


};





