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
	void showNode() const;
	void showToAdmin() const;
	char* getItemName();
	~ItemNode();
	friend class ItemList;

};
