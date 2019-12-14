#include "pch.h"
#pragma once
#include "ItemList.h"
#include "ItemNode.h"
#include "Item.h"
#include <string.h>
#include<iostream>
using namespace std;




ItemList::ItemList() 
{
	size = 0;
	head = tail = nullptr;
}

void ItemList::insert(Item& item) 
{
	  ItemNode* newItem = new ItemNode(item);
	  size++;

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

bool ItemList::isEmpty()
{
	if (!head)
		return true;
		return false;
}

int ItemList::getSize()
{
	int size = 0;
	ItemNode* counter = this->head;
	while (counter)
	{
		counter = counter->next;
		size++;
	}
	return size;
}

Item* ItemList::getItem(const char* itemName)  // return a pointer or a reference to the item?
{
	ItemNode* temp = this->head; // pointer or reference?
		

	while (temp)
	{
		if ((strcmp(temp->item->getItemName(), itemName)) == 0)
		{
			return  temp->item;
			break;
		}
	
		temp = temp->next;
	}

}

bool ItemList :: removeSingle(const char* ItemName) // Todo
{

	ItemNode* temp = this->head;
	ItemNode* save, *NodeToRemove;
	while (temp)
	{
		if (strcmp(temp->next->item->getItemName(), ItemName) == 0)
		{
			save = temp->next;
			temp->next = temp->next->next;
			delete save->item;
			delete save;
			return true;
		}
	}
	cout << "there is no such item , please try again" << endl;
	return false;
}

bool ItemList::removeSingle(Item& item)
{


	return false;
}