#include "Store.h"
#include <iostream>
using namespace std;

Store::Store() {}

void Store::addItem(string name, float price, int quantity)
{
    Item* item = new Item;
    item->name = name;
    item->price = price;
    item->quantity = quantity;

    inventory.insert(pair<string, Item*>(name, item));
}

bool Store::buyItem(Person *person, string itemName)
{
    if (inventory.count(itemName) == 1) {
        Item* item = inventory[itemName];
        cout << "Price: " << item->price << " Quantity: " << item->quantity << endl;
        cout << "How many would you like to buy?" << endl;
        int amount;
        cin >> amount;
        if (amount <= item->quantity) {
            float total = item->price * amount;
            bool transaction = person->spendMoney(total);
            // This is where the transaction goes through
            if (transaction) {
                // Subtract from total
                item->quantity -= amount;
                if (item->quantity == 0) {
                    delete item;
                    inventory.erase(itemName);
                }
                // Report to user
                cout << "You were able to purchase " << itemName << "\n Your new account balance is $" << person->getBalance() << endl;
                return true;
            }
            else {
                cout << "You only have $" << person->getBalance() << " in your account. The total was " << total << endl;
                return false;
            }
        }
        else {
            cout << "There are only " << item->quantity << " avaliable for purchase." << endl;
            return false;
        }
    }
    // If item does not exist
    else {
        cout << itemName << " does not exist in the store's inventory." << endl;
        return false;
    }   
}

void Store::showInventory() {
    for (auto& i : inventory) {
        string name = i.first;
        Item* item = i.second;

        cout << name << " | Price: $" << item->price << " Quantity: " << item->quantity << endl;
    }
}
