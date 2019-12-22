#pragma once

class Item;


class ItemNode
{
private:

	Item* item;
	ItemNode* next;

public:

	ItemNode();
	ItemNode(Item& newItem);
	void showNode();
	char* getItemName();
	~ItemNode();
	friend class ItemList;

};
