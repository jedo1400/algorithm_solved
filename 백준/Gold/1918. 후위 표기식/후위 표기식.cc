#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> op;
	const int priority[8] = { -1, 0, 1, 0, 0, 0, 0, 1 };

	for (auto &i : str) {
		if (i == '(')
			op.push('(');

		else if (i == ')') {
			while (!op.empty() && op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			
			op.pop();
		}

		else if (i < 'A') {
			while (!op.empty() && priority[op.top()-'('] >= priority[i-'(']) {
				cout << op.top();
				op.pop();	
			}
		
			op.push(i);
		}

		else
			cout << i;
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
}