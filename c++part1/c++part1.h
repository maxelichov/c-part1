#pragma once
using namespace std;
#define maxFeedbackLen 100
#define maxLen 31
using namespace std;
#define EXIT 3
#define ExitBuyerMenu 5
#define EXITadminMenu 4
const char* Categories[] = { "Children" , "Clothing" , "Electricity" , "Office" };
enum eCategory { Children, Clothing, Electricity, Office };
#define TotalCategories 4

//FUNCTION'S DECLARATIONS :
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayMenu();
bool validateChoice(int& MenuChoice);
void addUser(Buyer*** AllBuyers, int& TotalBuyerslogSize, int& TotalBuyersPhysSize, int& Choice, Seller*** AllSellers, int& TotalSellerslogSize,
	int& TotalSellersPhysSize);
void cleanBuffer();
void AddtoSeller(Seller* Sellers);
void addItemToSeller(Seller* Sellers, Item* item);
void addFeedback(Buyer* TheBuyer);
bool IsSellerInSystem(Seller** Sellers, const int& TotalSellerslogSize, char* username, char* password, int& index);
bool IsBuyerInSystem(Buyer** Buyers, const int& TotalBuyersLogSize, char* username, char* password, int& index);
bool IfPurchasedFrom(char* TheSeller, Buyer* TheBuyer);
void GiveFeedbackToSeller(char* feedback, Buyer* TheBuyer, char* SellerName);
void FindAndAddItem(const int& CategoryChoice, Buyer* TheBuyer, Seller** AllSellers, int Sellers_sz);
void addItemtobuyer(Buyer* TheBuyer, Seller** AllSellers, const int& TotalSellerslogSize);
bool ValidateCategory(int& choice);
void AddItemtobuyerFINAL(Buyer* TheBuyer, Seller** AllSellers, int& Sellers_sz, char* TheSeller, int& serialNumber, const char* Category);
void InsertToBuyersCart(Buyer* TheBuyer, Seller* TheSeller, Item* item);
void Register(Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize);
bool validateRegisterMenu(int& choice);
void RegisterMenu(int& choice, Buyer*** AllBuyers, int& TotalBuyersLogSize, int& TotalBuyersPhysSize,
	Seller*** AllSellers, int& TotalSellerslogSize, int& TotalSellersPhysSize);
void caseBuyer(Buyer* TheBuyer, Seller** AllSellers, int& TotalSellerslogSize);
void displayBuyerMenu(Buyer* TheBuyer);
void SignIn(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize);
void Adminlogin(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize);
void caseSeller(Seller* TheSeller);
void ShowStock(Seller* TheSeller);
void MakeAPurchase(Buyer* TheBuyer);
void deleteSellers(Seller** AllSellers, int& TotalSellerslogSize);
void deleteBuyers(Buyer** AllBuyers, int& TotalBuyerslogSize);
void ChooseCertainItemsFromCart(Buyer* TheBuyer);
void displayAdminMenu(Buyer** AllBuyers, Seller** AllSellers, int& TotalBuyerslogSize, int& TotalSellerslogSize);
void ShowAllBuyers(Buyer** AllBuyers, int& size);
void ShowAllSellers(Seller** AllSellers, int& size);
bool UsernameExists(Buyer** AllBuyers, int& TotalBuyerslogSize, Seller** AllSellers, int& TotalSellerslogSize, char* username);
void ShowMerch(Buyer* TheBuyer);
void showSameItems(Seller** AllSellers, int& TotalSellersLogSize);
////////////////////////////////////////////////////////////////////////////////////////////////