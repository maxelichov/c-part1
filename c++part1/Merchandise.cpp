#include "pch.h"
#include "Merchandise.h"
#include "Item.h"
#include "Department.h"


Merchandise::Merchandise()  // C'TOR
{
	NumOfDepartments = 0;
	TotalNumOfItems = 0;
	
}

int Merchandise::getNumOfDepartments() const
{
	return NumOfDepartments;
}

void Merchandise::setNumOfDepatrments(const int& newNumOfDepartments)
{
	NumOfDepartments = newNumOfDepartments;
}

void Merchandise::setItemToDepartment(Item& itemToAdd, int& department)
{
	if (NumOfDepartments == 0) // no departments in the seller's merch, need to allocate.
	{
		Departments[0] = new Department(department); /*allocating unnecessary space in the department*/
		Departments[0]->addItem(itemToAdd);
		NumOfDepartments++;
	}
	else  // at least one department exists in seller's merch
	{
		bool Inserted = false;
		for (int i = 0; i < NumOfDepartments; i++)
		{
			if (Departments[i]->getDepartment() == department) // if we found the matching department for the item
			{
				Departments[i]->addItem(itemToAdd);
				Inserted = true;
			}
		}
		if (!Inserted) // if we didnt find a matching department then we gonna have to create one.
		{
			Departments[NumOfDepartments] = new Department(department); /*need to fix. were allocating unnecessary space in the department*/
			Departments[NumOfDepartments]->addItem(itemToAdd);
			NumOfDepartments++;
			/* need to do size++ in the Department[department]*/
		}

	}
}

Merchandise::~Merchandise()
{
	delete[] Departments;


}


