#include "pch.h"
#include "Department.h"
#include "ItemList.h"
#include <string.h>



Department::Department() 
{

}

Department::Department(int& cat)
{
	department = (eCategory)cat;
}

void Department::addItem(Item& item)
{
	if (stock == nullptr)
	{
		stock = new ItemList();
	}
	stock->insert(item);
}

Department::~Department()
{
	delete stock;
}

int Department:: getDepartment()
{
	return (int)department;
}

ItemList* Department::getStock()
{
	return stock;
}

const char* Department:: getDepartment(const char* category)
{
	return Categories[getDepartment()];
}

void Department::FindItemByName(const char* ItemName, int& counter)
{
	stock->showWantedItem(ItemName, counter);
}