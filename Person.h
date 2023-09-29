#pragma once
#include <string>
#include <map>
#include "Account.h"
using namespace std;

class Person
{
public:
	Person(float accountBalance);
	Person(int userId, string name);
	Person(int userId, string name, float accountBalance);
	~Person();

	bool checkId(int id);
	void addItem(string name, int quantity);
	float getBalance();
	bool spendMoney(float amount);
private:
	string name;
	Account* account;
	int userId;
	map<string, int> inventory;
};

