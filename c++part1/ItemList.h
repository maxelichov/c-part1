#pragma once

class ItemNode;
class Item;
class ShoppingCart;

class ItemList
{
private:
	int size;
public:
	ItemNode* head, *tail;

	ItemList();
	void insert(Item& item);
	bool removeSingle(Item& item);
	bool removeSingle(const char* ItemName); 
	void removeAllItems(); 
	void removeAllItemsFromBuyer();
	Item* getItem(int& SerialNumber); //return a pointer or reference?
	int getSize();
	bool isEmpty(); 
	void showList();
	void updateItemList(ShoppingCart* NewCart);

	
	~ItemList(); // for(all nodes) { delete node}
};