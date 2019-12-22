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
	void setNumOfDepatrments(const int& newNumOfDepartments);
	int getNumOfDepartments() const;
	int getTotalNumOfItems() const;
	bool haveDepartment(const char* category);
	void ShowDepartment(const char* department) const;
	Item* getItemOfCategory(const char* Category,int& SerialNumber);
	void DisplayItemByName(const char* ItemName, int& counter);
	/*void RemoveItem(Item& itemToRemove);  // to do */
/*const Item& GetItemFromStok(Item& ItemToGet);*/ // to do//


};