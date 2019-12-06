#pragma once
#define ItemNameMAXlen 50



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


public:
	Item() = default;
	Item(char* name, int price,int category); // ctor //
	~Item(); // dtor//
	bool setItemName(const char* name);
	bool setItemPrice(int price);
	/*bool setItemSerialNumber(int* serialNumber);*/ //serial number will be automatically by the system?
	bool setCategory(int itemCategory);

	char* getItemName();
	int		getItemPrice();
	int getItemSerialNumber();
	int		getItemCategory();
};

int Item::ItemSerialNumber = 0;