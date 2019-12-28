#pragma once
#include "pch.h"
#include "FeedbackList.h"
#include "feedbacknode.h"

FeedbackList::FeedbackList()
{
	head = tail = nullptr;
	TotalNumOfFeedbacks = 0;
}


void FeedbackList ::insert(char* Feedback, char* BuyerName)
{
	FeedbackNode* Fnode = new FeedbackNode(Feedback, BuyerName);
	TotalNumOfFeedbacks++;

	if (head == nullptr) // list is empty
	{
		head = tail = Fnode;
	}

	else // list is not empty, insert at the head.
	{
		Fnode->next = head;
		head = Fnode;
	}

}

FeedbackList::~FeedbackList()
{
		FeedbackNode* node;
		while (head)
		{
			node = head->next;
			delete head; 
			head = node;
		}
		head = tail = nullptr;
	
}