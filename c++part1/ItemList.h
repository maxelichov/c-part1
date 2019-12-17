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
	bool removeSingle(Item& item);
	bool removeSingle(const char* ItemName); 
	void removeAllItems(); 
	Item& getItem(Item& item); //TODO
	Item* getItem(const char* itemName); //return a pointer or reference?
	int getSize();
	bool isEmpty(); 
	void showList();

	
	~ItemList(); // for(all nodes) { delete node}
};