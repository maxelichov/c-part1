#pragma once

class ItemNode;
class Item;

class ItemList
{
private:
	int size;
public:
	ItemNode* head, * tail;

	ItemList();
	void insert(Item& item);
	bool removeSingle(Item& item);//TODO
	bool removeSingle(const char* ItemName); //Todo
	/*bool removeSingle( const char* serialNumber);//TODO*/
	bool removeAllItems(const char* itemName); //TODO
	Item& getItem(Item& item); //TODO
	Item* getItem(const char* itemName); //return a pointer or reference?
	int getSize();
	bool isEmpty(); 

	~ItemList(); // for(all nodes) { delete node}
};