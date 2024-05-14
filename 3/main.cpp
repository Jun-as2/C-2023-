#include <iostream>
#include <vector>

using namespace std;

class Account {
	string name;
	int money;
public:
	Account(string _name, int _money) {
		name = _name;
		money = _money;
	}

	string getName() {
		return name;
	}
	int getMoney() {
		return money;
	}

	void setMoney(int _money) {
		money = _money;
	}
};

class Bank {
	vector<Account> acc;
public:
	void createAccount(Account a) {
		acc.push_back(a);
	}
	void deposit(string name, int money) {
		for (int i = 0; i < acc.size(); i++) {
			if (acc[i].getName() == name) {
				acc[i].setMoney(acc[i].getMoney() + money);
			}
		}
	}
	void withdraw(string name, int money) {
		for (int i = 0; i < acc.size(); i++) {
			if (acc[i].getName() == name) {
				acc[i].setMoney(acc[i].getMoney() - money);
			}
		}
	}
	void transfer(string out, string in, int money) {
		int outIndex;
		int inIndex;
		for (int i = 0; i < acc.size(); i++) {
			if (acc[i].getName() == out) {
				outIndex = i;
			}
			if (acc[i].getName() == in) {
				inIndex = i;
			}
		}
		acc[outIndex].setMoney(acc[outIndex].getMoney() - money);
		acc[inIndex].setMoney(acc[inIndex].getMoney() + money);
	}
	void print() {
		for (int i = 0; i < acc.size(); i++) {
			cout << "Account name = " << acc[i].getName() << ", money = " << acc[i].getMoney() << endl;
		}
		cout << "-------------------------------" << endl;
		cout << endl;
	}
};



int main()
{
	Bank bank;
	bank.createAccount(Account("Kim", 3000));
	bank.createAccount(Account("Lee", 2000));
	bank.createAccount(Account("Choi", 10000));
	bank.deposit("Kim", 1000);
	bank.withdraw("Lee", 1000);
	bank.transfer("Choi", "Lee", 5000);
	bank.print();
	bank.transfer("Kim", "Choi", 3000);
	bank.print();
}