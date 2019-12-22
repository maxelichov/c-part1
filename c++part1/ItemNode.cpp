#pragma once
#include "pch.h"
#include "ItemNode.h"
#include "Item.h"
#pragma once

ItemNode::ItemNode() 
{
	item = nullptr;
	next = nullptr;
}

ItemNode::ItemNode(Item& newItem)
{
	item = &newItem;
	next = nullptr;
}
ItemNode ::~ItemNode() // maby need to fix on the future.
{
	delete item;
}
void ItemNode::showNode()
{
	this->item->showTheItem();
}

char* ItemNode :: getItemName()
{
	return getItemName();
}