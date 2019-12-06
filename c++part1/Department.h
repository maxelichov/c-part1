#pragma once

class ItemList;
class Item;

class Department
{
public:
	enum eCategory { Children, Clothing, Electricity, Office };
private:
	eCategory department;
	ItemList* stock;

public:
	Department();
	Department(int departmentName);

	void addItem(Item& item);

	~Department();
};