#include "pch.h"
#include "shoppingcart.h"
#pragma once

bool ShoppingCart::AddItemToCart(Item& ChosenItem)
{

	Cart->insert(ChosenItem);
	TotalPrice += ChosenItem.getItemPrice();
	ChosenItem.isInShopingCart = true;
	return true;

}

void ShoppingCart::ShowCart()
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

void ShoppingCart::RemoveAllItems()
{
	TotalPrice = 0;
	Cart->removeAllItemsFromBuyer();

}

ShoppingCart :: ~ShoppingCart()
{
	Cart->removeAllItemsFromBuyer();
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
	TotalPrice += NewCart->GetTotalPrice();
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
