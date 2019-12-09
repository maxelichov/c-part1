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
	/*where is the d'tor?*/
	friend class ItemList;

};
