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

void ShoppingCart::RemoveFromCart(Item& ChosenItem)
{	
	

	if (!Cart->removeSingle(ChosenItem))
	{
		return;
	}
	TotalPrice -= ChosenItem.getItemPrice();
	ChosenItem.isInShopingCart = false;
}

void ShoppingCart::RemoveFromCart(const char* ItemName)
{
	/*RemoveFromCart(Cart->getItem(ItemName));*/ //TODO.


}

bool ShoppingCart::isEmpty()
{
	return Cart->isEmpty();
}

void ShoppingCart::RemoveAllItems()
{
	Cart->removeAllItems();
}
ShoppingCart :: ~ShoppingCart()
{
	delete Cart;
}

int ShoppingCart::GetTotalPrice()
{
	return TotalPrice;
}