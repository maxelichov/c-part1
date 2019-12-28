#pragma once
#define ItemNameMAXlen 50

#include "Seller.h"
#include "BuyerAndSeller.h"


class Item
{
public:
	enum eCategory { Children, Clothing, Electricity, Office };
private:
	static int ItemSerialNumber;
	char* ItemName;
	int ItemPrice;
	int SerialNumber;
	eCategory itemCategory;
	Seller* TheSeller;
	BuyerAndSeller* TheBS;
	bool hasBeenBought = false;
	Item(const Item& other); // to prevent copy ctor.


public:

	Item() = default;
	Item(char* name, int price,int category); 
	~Item(); 
	bool setItemName(const char* name);
	bool setItemPrice(int price);
	bool setCategory(int itemCategory);
	char* getItemName() const;
	int	getItemPrice() const;
	int getItemSerialNumber() const;
	int	getItemCategory() const;
	void showTheItem() const;
	void showTheItemToAdmin() const;
	void setSeller(Seller* TheSeller);
	void setBS(BuyerAndSeller* TheBS);
	Seller* getSeller();
	BuyerAndSeller* getBS();
	bool getStatus();
	void setStatus(bool status);
};

