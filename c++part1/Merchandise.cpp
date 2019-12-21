#pragma once
#include "pch.h"
#include "Merchandise.h"
#include "Item.h"
#include "Department.h"
#include "ItemList.h"
#include <string.h>
#pragma once

const char* Categories1[] = { "Children" , "Clothing" , "Electricity" , "Office" };

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
	TotalNumOfItems++;
}

Merchandise::~Merchandise()
{
	for (int i = 0; i < this->getNumOfDepartments(); i++)
	{
		delete Departments[i];
	}


	/*delete Departments;*/
}

bool Merchandise::haveDepartment(const char* category)
{
	for (int i = 0; i < getNumOfDepartments(); i++)
	{
		if (strcmp(Categories1[this->Departments[i]->getDepartment()] , category)==0)
			return true;
    }
	return false;
}

void Merchandise::ShowDepartment(const char* department) const
{
	for (int i = 0; i < this->getNumOfDepartments(); i++)
	{
		if (Categories1[Departments[i]->getDepartment()] == department)
		{
			this->Departments[i]->getStock()->showList();
		}
	}
}

Item* Merchandise:: getItemOfCategory(const char* Category,int& SerialNumber)
{
	Item item;
	for (int i = 0; i < NumOfDepartments; i++)
	{
		if (Departments[i]->getDepartment(Category) == Category)
		{
			 return Departments[i]->getStock()->getItem(SerialNumber);
		}
    }
	return nullptr;
}