
#include "ItemNode.h"

ItemNode::ItemNode() 
{
	next = nullptr;
}

ItemNode::ItemNode(Item& newItem) : ItemNode()
{
	item = &newItem;
	next = nullptr;
}