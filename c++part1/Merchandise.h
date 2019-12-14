#pragma once

#define TotalDepartments 4
class Department;
class Item;


class Merchandise
{
private:

	int NumOfDepartments;
	int TotalNumOfItems;
	Department* Departments[TotalDepartments];


public:


	Merchandise();
	~Merchandise(); // dtor //
	void setItemToDepartment(Item& itemToAdd , int& department);
	/*void RemoveItem(Item& itemToRemove);  // to do */
	/*const Item& GetItemFromStok(Item& ItemToGet);*/ // to do//
	void setNumOfDepatrments(const int& newNumOfDepartments);
	void setTotalNumOfItems(const int& totalNumOfItems);
	int getNumOfDepartments() const;
	int getTotalNumOfItems() const;
	bool haveDepartment(const char* category);
	void ShowDepartment(const char* department);
	Item* getItemOfCategory(const char* Category,const char* ItemName);


};