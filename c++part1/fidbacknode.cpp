
#include "fidbacknode.h"

FidbackNode::FidbackNode()
{
	BuyerThatGaveFidback = nullptr;
	TheFidback = nullptr;
	next = nullptr;
}

FidbackNode::FidbackNode(char* BuyerThatGaveFidback, char* TheFidback)
{
	FidbackNode* NewFidbackNode = new FidbackNode(BuyerThatGaveFidback, TheFidback);
}



