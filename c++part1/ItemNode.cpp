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

void ItemNode::showNode()
{
	this->item->showTheItem();
}