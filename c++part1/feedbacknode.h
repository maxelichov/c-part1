#pragma once

class FeedbackNode
{
private:

	char* BuyerThatGaveFeedback;
	char* TheFeedback;
	FeedbackNode* next;

public:
		
	FeedbackNode();
	FeedbackNode(char* Feedback, char* BuyerName);


	friend class FeedbackList;
};