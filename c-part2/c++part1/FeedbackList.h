
#pragma once
class FeedbackNode;

class FeedbackList
{
private: 
	
	int TotalNumOfFeedbacks;
	FeedbackNode* head, * tail;
	

public:
	
	FeedbackList();
	void insert(char* Feedback, char* BuyerName);
	~FeedbackList();

};
