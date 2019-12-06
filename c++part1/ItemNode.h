#pragma once

class Item;


class ItemNode
{

	Item* item;
	ItemNode* next;

public:

	ItemNode();
	ItemNode(Item& newItem);

	friend class ItemList;

};
