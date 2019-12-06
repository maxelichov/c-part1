#include "pch.h"
#include "ItemList.h"
#include "ItemNode.h"


ItemList::ItemList() 
{
	head = tail = nullptr;
}

void ItemList::insert(Item& item) {
	/*
	Check if item (serial number) already exists
	*/

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