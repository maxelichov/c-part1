#pragma once

class ItemList;
class Item;

class Department
{
public:
	enum eCategory { Children, Clothing, Electricity, Office };
	const char* Categories [4] = { "Children" , "Clothing" , "Electricity" , "Office" };
private:
	eCategory department;
	ItemList* stock;

public:
	Department();
	Department(int& departmentName);

	void addItem(Item& item);
	int getDepartment();
	const char* getDepartment(const char* category);
	ItemList* getStock();

	~Department();
};