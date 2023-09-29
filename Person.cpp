#include "Person.h"

Person::Person(float accountBalance) {
    userId = 0000;
    name = "John Doe";
    account = new Account(accountBalance);
}

Person::Person(int userId, string name)
{
    this->userId = userId;
    this->name = name;
    account = new Account();
}

Person::Person(int userId, string name, float accountBalance)
{
    this->userId = userId;
    this->name = name;
    account = new Account(accountBalance);
}

Person::~Person()
{
    delete account;
}

bool Person::checkId(int id)
{
    return (id == userId) ? true : false;
}

void Person::addItem(string name, int quantity)
{
    inventory.insert(pair<string,int>(name, quantity));
}

float Person::getBalance() {
    return account->getCurrentBalance();
}

bool Person::spendMoney(float amount) {
    return account->spendMoney(amount);
}