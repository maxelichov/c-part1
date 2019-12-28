
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
	int GetTotalPrice(); 
	bool isEmpty();
	void ShowCart() const;
	void RemoveAllItems(int& flag);
	Item* getItemFromCart(int& ItemSerialNumber);
	void updateCart(ShoppingCart* newCart);
	int getItemListSize() const;
	ItemList* getCartList();
	bool checkIfItemExists(Item& item);
	void changeItemsStatus();
	/*void RemoveFromCart(Item& ChosenItem);
	void RemoveFromCart(const char* ItemName);*/
	/*void DecreaseTotalPriceByName(const char* ItemName);*/

};