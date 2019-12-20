#pragma once

class FeedbackList;

class Feedback
{
private:

	FeedbackList* FList;

public:

	Feedback();
	void AddFeedbackToSeller(char* Feedback , char* BuyerName);
	~Feedback();
};