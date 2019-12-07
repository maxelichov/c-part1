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
	void removeSingle(Item& item);
	void removeSingle(char* serialNumber);
	void removeAllItems(char* itemName);
	Item& getItem(Item& item);
	Item& getItem(char* itemName);
	int getSize();
	bool isEmpty();

	~ItemList(); // for(all nodes) { delete node}
};