
#include "Merchandise.h"
#include "Item.h"
#include "Department.h"


enum eCategory { Children, Clothing, Electricity, Office };

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
	if (NumOfDepartments == 0) // no departments in the seller's merch
	{
		Departments[NumOfDepartments] = new Department(department);
		Departments[NumOfDepartments]->addItem(itemToAdd);

	}

}

Merchandise::~Merchandise()
{
	delete[] Departments;


}


