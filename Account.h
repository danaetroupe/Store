#pragma once
class Account
{
public:
	Account() { accountBalance = 0; }
	Account(float balance) { accountBalance = balance; }

	void despoitMoney(float money) { accountBalance += money; }
	float getCurrentBalance() { return accountBalance; }

	// Return true if money can be spent, false if not
	bool spendMoney(float money) {
		if (money <= accountBalance) {
			accountBalance -= money;
			return true;
		}
		else { return false; }
	}
private: 
	float accountBalance;
};

