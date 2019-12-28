#pragma once
#include "pch.h"
#include "ItemList.h"
#include "ItemNode.h"
#include "Item.h"
#include "shoppingcart.h"
#include "Seller.h"
#include <string.h>
#include <iostream>
using namespace std;




ItemList::ItemList() 
{
	size = 0;
	head = tail = nullptr;
}

bool ItemList::insert(Item& item) 
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
	return true;
}

ItemList::~ItemList()
{
	ItemNode* node;
	while (head)
	{
		node = head->next;
		delete head; // we allocated a new itemnode so we delete.
		head = node;
	}
	head = tail = nullptr; // set the itemlist as empty
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

Item* ItemList::getItem(int& SerialNumber)  // return a pointer or a reference to the item?
{
	ItemNode* temp = this->head; // pointer or reference?
		

	while (temp)
	{
		if (temp->item->getItemSerialNumber() == SerialNumber)
		{
			return  temp->item;
			break;
		}
	
		temp = temp->next;
	}

	return nullptr;
}

bool ItemList :: removeSingle(const char* ItemName) 
{

	ItemNode* temp = this->head;
	ItemNode* save, *NodeToRemove;
	while (temp)
	{
		if (temp == head)
		{
			if (strcmp(temp->item->getItemName(), ItemName) == 0)
			{
				if (temp == tail) // if the temp is also the head and tail and we want to remove it (1 item on list)
				{
					temp->item = nullptr; // the item is by ref from seller so we dont delete it(so wont be deleted in seller's merch)
					delete temp; // for buyer we allocated a new item node
					head = temp = nullptr; // mark as empty
					size = 0;
					return true;
				}

				// meaning the temp is not also the tail, but only the head.
				else
				{
					head = temp->next;
					temp->item = nullptr;
					delete temp;
					size--;
					return true;
				}
			}

		}
		
		else  if (strcmp(temp->next->item->getItemName(), ItemName) == 0)
		{
			save = temp->next;
			temp->next = temp->next->next;
			save->item = nullptr;
			delete save;
			size--;
			return true;

		}
		temp = temp->next;
	}
	
	cout << "there is no such item , please try again" << endl;
	return false;
}

//bool ItemList::removeSingle(Item& item)
//{
//	ItemNode* temp = this->head, *save;
//	while (temp)
//	{
//		if (temp->item == &item)
//		{
//			save = temp->next;
//			temp->next = temp->next->next;
//			delete save;
//			return true;
//		}
//		temp = temp->next;
//	}
//	cout << "there is no such item , please try again" << endl;
//	return false;
//}

void ItemList::removeAllItems()
{
	this->~ItemList();
}

void ItemList::removeAllItemsFromBuyer(int& flag)
{
		size = 0;
		ItemNode* node;
		while (head)
		{
			node = head->next;
			if (flag) // meaning the items were bought, mark their status as true so no one can add/purchase them anymore.
				head->item->setStatus(true);
			else if (!flag)
				head->item->setStatus(false);

			head->item = nullptr; // mark as empty we get the item by ref from the seller so we dont delete it)
			delete head; // we allocated a new itemnode so we delete.
			head = node;
		}
		head = tail = nullptr; // set the itemlist as empty
}

void ItemList::showList()
{
	int counter = 0;
	ItemNode* temp = head;
	while (temp)
	{
		temp->showNode();
		temp = temp->next;
		counter++;

	}
	if (counter == 0)
		cout << "Your cart is empty!" << endl;
}

void ItemList::updateItemList(ShoppingCart* NewCart)
{
	head = NewCart->getCartList()->head;
	tail = NewCart->getCartList()->tail;
	size = NewCart->getItemListSize();

}

void ItemList::changeItemStatus() // change all items status to true 
{
	ItemNode* temp = head;
	while (temp)
	{
		temp->item->setStatus(false);
		temp = temp->next;

	}
}

Seller** ItemList::getAllSellersFromList(int& Arr_sz)
{
	int SellersArrlogsize = 0;
	Seller** SellersArr = new Seller * [size]; // will have maximum size num of different sellers(size items)
	for (int i = 0; i < size; i++)
		SellersArr[i] = nullptr;

	bool InArr = false;
	ItemNode* node = head; 
	while (node) // run on all the items list
	{
		for (int i = 0; i < SellersArrlogsize; i++) // run on all the sellers array that we will make from the list of items
		{
			Seller* TheSeller = node->item->getSeller();
			if (strcmp(SellersArr[i]->getUsername(), TheSeller->getUsername()) == 0)
			     InArr = true;
		}
		if (!InArr) // if we didnt find the seller in the array, meaning we need to add him
		{
			SellersArr[SellersArrlogsize] = node->item->getSeller();
			SellersArrlogsize++;
		}
		node = node->next;
		InArr = false;
	}
	Seller** temp = new Seller * [SellersArrlogsize];
	for (int i = 0; i < SellersArrlogsize; i++)
		temp[i] = SellersArr[i];

	delete[]SellersArr;
	Arr_sz = SellersArrlogsize; // update the array size by ref
	return temp;
}

void ItemList:: showWantedItem(const char* itemName,int& counter)
{
	ItemNode* temp = head;
	while(temp)
	{
		if (strcmp(temp->getItemName(), itemName) == 0)
		{
			temp->showToAdmin();
			cout << endl;
			counter++;
		}
		temp = temp->next;
	}
}