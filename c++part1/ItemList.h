#pragma once

class ItemNode;
class Item;
class ShoppingCart;
class Seller;

class ItemList
{
private:
	int size;
public:
	ItemNode* head, *tail;

	ItemList();
	bool insert(Item& item);
	bool removeSingle(const char* ItemName); 
	void removeAllItems(); 
	void removeAllItemsFromBuyer(int& flag);
	Item* getItem(int& SerialNumber); 
	int getSize();
	bool isEmpty(); 
	void showList();
	void updateItemList(ShoppingCart* NewCart);
	void changeItemStatus();
	Seller** getAllSellersFromList(int& size);
	void showWantedItem(const char* itemName,int& counter);
	~ItemList(); // for(all nodes) { delete node}

	/*bool removeSingle(Item& item);*/
};