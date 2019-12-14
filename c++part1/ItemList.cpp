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
	removeAllItems();
	
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
	ItemNode* temp = head; // pointer or reference?
		
	while (temp)
	{
		if ((strcmp(temp->item->getItemName(), itemName)) == 0)
		{
			return  temp->item;
			break;
		}
		temp = temp->next;
	}
	return nullptr; // item wasn't found
}

bool ItemList :: removeSingle(const char* ItemName) // Todo
{
	ItemNode* temp = this->head;
	ItemNode* NodeToRemove;
	while (temp)
	{
		if (strcmp(temp->item->getItemName(), ItemName) == 0) // need to remove the node
		{
			if (temp == this->head) // if the node we are trying to remove is the first in the linked list
			{
				if (temp == this->tail) // if the node is also the last ( 1 item in linked list)
				{
					this->head = this->tail = nullptr;
					delete temp->item;
					delete temp;
					return true;
				}
				else // temp is only the first in linked last but not the last ( more than 1 item in list)
				{
					this->head = temp->next;
					delete temp->item;
					delete temp;
					return true;
				}
			}

		}
		if (temp->next != nullptr)
		{
			if (strcmp(temp->next->item->getItemName(), ItemName) == 0)
			{
				NodeToRemove = temp->next;
				temp->next = temp->next->next;
				delete NodeToRemove->item;
				delete NodeToRemove;
				return true;
			}

		}
		temp = temp->next;
		
	}
	cout << "there is no such item , please try again" << endl;
	return false;
}

bool ItemList::removeSingle(Item& item)
{
	ItemNode* temp = this->head, * save;
	while (temp)
	{
		if (temp->item == &item)
		{
			save = temp->next;
			temp->next = temp->next->next;
			delete save;
			return true;
		}
		temp = temp->next;
	}
	cout << "there is no such item , please try again" << endl;
	return false;
}

void ItemList::removeAllItems()
{
	ItemNode* temp;
	while (head)
	{
		temp = head->next;
		delete head->item;
		delete head;

		head = temp;
	}
}

void ItemList::showList()
{
	ItemNode* temp = head;
	while (temp)
	{
		temp->showNode();
		temp = temp->next;

     }
}