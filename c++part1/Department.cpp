#include "pch.h"
#include "Department.h"
#include "ItemList.h"



Department::Department()
{
	department = (eCategory)5; // just to put some value.
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