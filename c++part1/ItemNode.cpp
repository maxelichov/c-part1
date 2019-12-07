#include "pch.h"
#include "ItemNode.h"

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