#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<string, string>> v(n);

	for (auto &i : v)
		cin >> i.first >> i.second;

	sort (v.begin(), v.end(),
	[](pair<string, string> &a, pair<string, string> &b) -> bool {
		if (a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	});

	for (auto &i : v)
		cout << i.first << ' ' << i.second << '\n';
}