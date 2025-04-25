#include <iostream>
#include <string>

using namespace std;

void solve(string &str, int l, int r, bool root = 1) {
	static bool display[100]{0,};
	
	int w = l;
	for (int i = l; i <= r; ++i)
		if (str[i] < str[w])
			w = i;
	
	display[w] = 1;

	for (int i = 0; i < str.length(); ++i)
		if (display[i])
			cout << str[i];
	cout << '\n';

	if (w+1 <= r) solve(str, w+1, r); // 오른쪽
	if (w-1 >= l) solve(str, l, w-1); // 왼쪽 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	solve(str, 0, str.length()-1);
}