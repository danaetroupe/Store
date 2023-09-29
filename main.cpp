#include "Account.h"
#include "Person.h"
#include "Store.h"
#include <iostream>
using namespace std;

int main() {
	Person* person = new Person(100);
	Store store;
	store.addItem("Bacon", 3.99, 3);
	store.addItem("Flowers", 5, 10);
	store.addItem("Wood", 27.32, 2);

	store.showInventory();

	string input = "";
	while (input != "QUIT") {
		cout << "What would you like to buy? (or enter 'QUIT')" << endl;
		string name;
		cin >> name;
		store.buyItem(person, name);
	}

	return 0;
}