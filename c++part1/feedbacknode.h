#pragma once

class FeedbackNode
{
private:

	char* BuyerThatGaveFeedback;
	char* TheFeedback;
	FeedbackNode* next;

public:
		
	FeedbackNode();
	FeedbackNode( const char* Feedback, char* BuyerName);
	~FeedbackNode();


	friend class FeedbackList;
};