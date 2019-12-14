#include "pch.h"
#include "shoppingcart.h"

bool ShoppingCart::AddItemToCart(Item& ChosenItem)
{

	Cart->insert(ChosenItem);
	TotalPrice += ChosenItem.getItemPrice();
	ChosenItem.isInShopingCart = true;
	return true;

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


ShoppingCart :: ~ShoppingCart()
{
	delete Cart;
}