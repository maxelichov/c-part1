#pragma once
#define ItemNameMAXlen 50
class Seller;


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
	void setSeller(Seller* TheSeller);
	Seller* getSeller();
	bool getStatus();
	void setStatus(bool status);
};

