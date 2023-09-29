#include "Person.h"
Person::Person(int userId, string name)
{
    this->userId = userId;
    this->name = name;
}

Person::Person(int userId, string name, float accountBalance)
{
}

Person::~Person()
{
}

bool Person::checkId(int id)
{
    return false;
}

void Person::addItem(string name, int quantity)
{
}
