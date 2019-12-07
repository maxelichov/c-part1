#include "pch.h"
#include "ItemList.h"
#include "ItemNode.h"


ItemList::ItemList() 
{
	size = 0;
	head = tail = nullptr;
}

void ItemList::insert(Item& item) 
{
	  ItemNode* newItem = new ItemNode(item);

	if (head == nullptr) // meaning the list is empty.
	{
		head = newItem;
		tail = newItem;
	}

	else // at least one product in the list
	{
		// Insert the new item at the list's head;
		newItem->next = head;
		head = newItem;
		
	}
}

ItemList::~ItemList()
{
	ItemNode* node;
	while (head)
	{
		node = head->next;
		delete head;
		head = node;
	}
	
}