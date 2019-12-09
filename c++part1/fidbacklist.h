
#pragma once
class FidbackNode;

class FidbackList
{
private: 
	
	int TotalNumOfFidbacks;

public:
	FidbackNode* head, *tail;
	
	FidbackList();
	insert(char* Bname, char* TheFeedback);
};
