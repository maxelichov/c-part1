#include "pch.h"
#include "shoppingcart.h"
#pragma once

using namespace std;
#include <iostream>

bool ShoppingCart::AddItemToCart(Item& ChosenItem)
{
	if ((!checkIfItemExists(ChosenItem))) // check if the item already in the cart or not
	{
		if (ChosenItem.getStatus() == true) // if the item has been bought already
		{
			cout << "Error: item " << ChosenItem.getItemName() << " with serial number " << ChosenItem.getItemSerialNumber() <<
				" has been bought already!" << endl;
			return false;
		}

		if (Cart->insert(ChosenItem))
		{
			TotalPrice += ChosenItem.getItemPrice();
			return true;
		}

	}

	cout << "This item is already in your cart!" << endl;
	
	return false;
}

void ShoppingCart::ShowCart() const
{
	Cart->showList();
}

//void ShoppingCart::RemoveFromCart(const char* ItemName)
//{
//
//	if (!Cart->removeSingle(ItemName))
//		return;
//
//	DecreaseTotalPriceByName(ItemName);
//}

//void ShoppingCart::DecreaseTotalPriceByName(const char* ItemName)
//{
//	Item* item = Cart->getItem(ItemName);
//	item->isInShopingCart = false;
//	TotalPrice -= item->getItemPrice();
//}

bool ShoppingCart::isEmpty()
{
	return Cart->isEmpty();
}

void ShoppingCart::RemoveAllItems(int& flag)
{
	TotalPrice = 0;
	Cart->removeAllItemsFromBuyer(flag);

}

void ShoppingCart::changeItemsStatus()
{
	Cart->changeItemStatus();
}

ShoppingCart :: ~ShoppingCart()
{
	delete Cart;
}

int ShoppingCart::GetTotalPrice()
{
	return TotalPrice;
}

Item* ShoppingCart::getItemFromCart(int& ItemSerialNumber)
{
	return(Cart->getItem(ItemSerialNumber));
}

void ShoppingCart::updateCart(ShoppingCart* NewCart)
{
	TotalPrice = NewCart->GetTotalPrice();
	Cart->updateItemList(NewCart);

}

ItemList* ShoppingCart::getCartList()
{
	return Cart;
}


int ShoppingCart::getItemListSize() const
{

	return Cart->getSize();

}

bool ShoppingCart::checkIfItemExists(Item& item)
{
	Item* Item;
	int Serial = item.getItemSerialNumber();
	Item = Cart->getItem(Serial);

	if (Item)
		return true;

	return false;
}
