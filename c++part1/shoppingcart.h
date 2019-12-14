
#pragma once
#include "Item.h"
#include "Seller.h"
#include "ItemList.h"

class ShoppingCart
{
private:

	ItemList* Cart;
	int TotalPrice;

public:

	ShoppingCart() : Cart(new ItemList()), TotalPrice(0) {}
	~ShoppingCart();
	bool AddItemToCart(Item& ChosenItem);
	void RemoveFromCart(Item& ChosenItem);
	void RemoveFromCart( const char* ItemName);
	int GetTotalPrice(); //Todo
	bool isEmpty();
};