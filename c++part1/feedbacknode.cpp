
#pragma once

#include"pch.h"
#include "feedbacknode.h"
#include <string.h>
#pragma warning(disable: 4996)


FeedbackNode::FeedbackNode()
{
	BuyerThatGaveFeedback = nullptr;
	TheFeedback = nullptr;
	next = nullptr;
}

FeedbackNode::FeedbackNode(char* Feedback, char* BuyerName)
{
	BuyerThatGaveFeedback = new char[strlen(BuyerName) + 1];
	strcpy(BuyerThatGaveFeedback, BuyerName);

	TheFeedback = new char[strlen(Feedback) + 1];
	strcpy(TheFeedback, Feedback);

	next = nullptr;
}





