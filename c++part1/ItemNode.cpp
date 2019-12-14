#include "pch.h"
#include "ItemNode.h"
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