#include "Department.h"
#include "ItemList.h"



Department::Department()
{
	department = (eCategory)5; // just to put some value.
	stock = nullptr;
}

Department::Department(int cat)
{
	department = (eCategory)cat;
	/*stock = new ItemList ();*/
}

void Department::addItem(Item& item)
{
	if (stock == nullptr)
	{
		stock = new ItemList;
	}

	stock->insert(item);
}

Department::~Department()
{
	delete stock;
}