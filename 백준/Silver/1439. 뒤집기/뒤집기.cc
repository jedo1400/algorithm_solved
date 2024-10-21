#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t_part{}, f_part{};
	string s;
	cin >> s;
	
	bool before = s[0] - 48;
	for (int i = 1; i < s.length(); ++i)
		if (s[i]-48 != before)
			before = s[i]-48, ++(before ? t_part : f_part);

	cout << max(t_part, f_part);
}