#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	while (true) {
		string operation;
		vector<int> _operand;
		vector<char> _operator;
		cout << "? ";
		getline(cin, operation);
		
		for (int i = 0; i < operation.length(); i++) {
			if (operation[i] == '+' || operation[i] == '*') {
				_operator.push_back(operation[i]);
			}
			else if ('1' <= operation[i] && operation[i] <= '9') {
				_operand.push_back((operation[i] - '0'));
			}
		}

		for (int i = 0; i < _operator.size(); i++) {
			if (_operator[i] == '*') {
				int a = _operand[i];
				int b = _operand[i+1];
				_operand.erase(_operand.begin() + i);
				_operand.erase(_operand.begin() + i);
				_operator.erase(_operator.begin() + i);

				_operand.insert(_operand.begin() + i, a * b);
			}
		}

		for (int i = 0; i < _operator.size(); i++) {
			if (_operator[i] == '+') {
				int a = _operand[i];
				int b = _operand[i + 1];
				_operand.erase(_operand.begin() + i);
				_operand.erase(_operand.begin() + i);
				_operator.erase(_operator.begin() + i);
				_operand.insert(_operand.begin() + i, a + b);
			}
		}

		cout << operation << " = " << _operand[0] << endl;

	}
}