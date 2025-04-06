#include <algorithm>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

#define INIT() E = "", R = "", separator = 0

void grant(bool table[][26], string &E, char &x, string &R) {
	if (x != '=') // +, -
		for (auto &i : E)
			for (auto &j : R)
				table[i-'A'][j-'a'] = x == '+' ? 1 : 0;
	
	else { // =
		for (auto &i : E)
			for (int j = 0; j < 26; ++j)
				table[i-'A'][j] = 0;

		for (auto &j : R)
			for (auto &i : E)
				table[i-'A'][j-'a'] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int index = 0;
	string log;

	while (cin >> log && log != "#") {
		bool table[26][26]{0,}; // [entity][permission]
		string E, R;
		char x;
		bool separator = 0; // 0 E, 1 R

		for (auto &i : log) {
			if (!separator) { // E
				if (i >= 'A')
					E.push_back(i);
				else // 연산자 (+, -, =) 찾으면
					x = i, separator = 1;
			}
			else {
				if (i != ',')
					R.push_back(i);
				else {
					grant(table, E, x, R);
					INIT();
				}
			}
		} grant(table, E, x, R);

		string result, before_entity, before_list;
		for (int i = 0; i < 26; ++i) {
			string list;
			for (int j = 0; j < 26; ++j)
				if (table[i][j])
					list.push_back(j+'a');
			
			sort(list.begin(), list.end());

			if (!list.empty()) {
				if (before_entity.empty() || list == before_list) {
					before_entity.push_back(i+'A');
					before_list = list;
				}
				else {
					result.append(before_entity + before_list);
					before_entity = i+'A', before_list = list;
				}
			}
		}

		result.append(before_entity + before_list);
		cout << ++index << ':' << result << '\n';
	}
}