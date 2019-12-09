#pragma once

class FidbackNode
{
private:
	char* BuyerThatGaveFidback;
	char* TheFidback;
	FidbackNode* next;

public:
		
	FidbackNode();
	FidbackNode(char* BuyerThatGaveFidback, char* TheFidback);

};