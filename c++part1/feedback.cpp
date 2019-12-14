#pragma once
#include "pch.h"
#include "feedback.h"
#include "FeedbackList.h"


Feedback::Feedback()
{
	FList = nullptr;
}

void Feedback:: AddFeedbackToSeller(char* Feedback, char* BuyerName)
{
	if (FList == nullptr) // if the list of feedbacks is empty
	{
		FList = new FeedbackList();
	}

	FList->insert(Feedback, BuyerName);
}