#pragma once
enum eCategory { Children, Clothing, Electricity, Office };

class Item
{
	

private:
	char* ItemName;
	int ItemPrice;
	char* ItemSerialNumber;
	eCategory itemCategory;
	

public:
	
	
	Item() = default;
	Item(  char* name, int price, char* serialNumber , eCategory); // ctor //
	~Item(); // dtor//
	bool setItemName(const char* name);
	bool setItemPrice(int price);
	bool setItemSerialNumber(char* serialNumber);
	bool setCategory(eCategory itemCategory);

	char*	getItemName();
	int		getItemPrice();
	char*	getItemSerialNumber();
	int		getItemCategory();
};


////////////////////////////////////////////////////////////////

class ItemNode
{
public:
	Item& item;
	ItemNode* next;

	ItemNode() = default;
	ItemNode(Item& newItem) : item(newItem) {};
	~ItemNode() = default; // TODO: check if need to delete item
};

class ItemList
{
private:
	int size;
public:
	ItemNode *head, *tail;

	ItemList() = default;

	void insert(Item& item);
	void removeSingle(Item& item);
	void removeSingle(char* serialNumber);
	void removeAllItems(char* itemName);
	Item& getItem(Item& item);
	Item& getItem(char* itemName);
	int getSize();
	bool isEmpty();

	~ItemList(); // for(all nodes) { delete node}
};



class Department
{
private:
	eCategory department;
	ItemList* stock;

public:
	Department() = default;
	Department(eCategory departmentName);
	
	void addItem(Item& item);

	~Department();
};









/////////////////////////////////////////////////////////////////////////////////////////////////////

									//MERCHANDISE//

////////////////////////////////////////////////////////////////////////////////////////////////
class Merchandise
{
private:

	int NumOfDepartments; 
	int TotalNumOfItems;
	Item** Departments;

public:
																			
	Merchandise(int NumOfDepartment = 0, int TotalNumOfItems = 0);
	/*~Merchandise(); // dtor //								
	void setItemToDepartment(Item& itemToAdd , int department);
	/*void RemoveItem(Item& itemToRemove);  // to do */
	/*const Item& GetItemFromStok(Item& ItemToGet);*/ // to do//
	void setNumOfDepatrments(const int newNumOfDepartments);
	void setTotalNumOfItems(const int totalNumOfItems);
	int getNumOfDepartments();
	int getTotalNumOfItems();
};