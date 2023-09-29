#include "Store.h"
#include <iostream>
using namespace std;

Store::Store() {}

void Store::addItem(string name, float price, int quantity)
{
    Item item;
    item.name = name;
    item.price = price;
    item.quantity = quantity;

    inventory.insert(pair<string, Item>(name, item));
}

bool Store::buyItem(Person *person, string itemName)
{
    if (inventory.count(itemName) == 1) {
        Item item = inventory[itemName];
        cout << "Price: " << item.price << " Quantity: " << item.quantity << endl;
        cout << "How many would you like to buy?" << endl;
        int amount;
        cin >> amount;
        if (amount <= item.quantity) {
            float total = item.price * amount;
            bool transaction = person->spendMoney(total);
            if (transaction) {
                cout << "You were able to purchase " << itemName << "\n Your new account balance is $" << person->getBalance() << endl;
                return true;
            }
            else {
                cout << "You only have $" << person->getBalance() << " in your account. The total was " << total << endl;
                return false;
            }
        }
    }
    // If item does not exist
    else {
        cout << itemName << " does not exist in the store's inventory." << endl;
        return false;

        /*string response;
        cin >> response;
        if (response == "YES") { showInventory(); }
        cout << "Would you like to try again? (Type Item Name OR 'QUIT' to exit)";
        cin >> response;
        if (response != "QUIT") { return buyItem(person, response); }
        else { return false; }*/
    }
    
}

void Store::showInventory() {
    for (auto i : inventory) {
        string name = i.first;
        Item item = i.second;

        cout << name << " | Price: $" << item.price << " Quantity: " << item.quantity << endl;
    }
}
