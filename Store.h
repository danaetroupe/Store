#pragma once
#include <string>
#include "Person.h"
using namespace std;

struct Item {
	string name;
	float price;
	int quantity;
};

class Store
{
public:
	Store();
	
	void addItem(string name, float price, int quantity);
	bool buyItem(Person* person, string itemName);
	void showInventory();

private:
	map<string, Item*> inventory;
};

