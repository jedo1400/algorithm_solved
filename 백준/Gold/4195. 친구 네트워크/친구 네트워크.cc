#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

string find(unordered_map<string, string> &parent, string n) {
	return parent[n] = parent[n] == n ? n : find(parent, parent[n]);
}

void merge(unordered_map<string, string> &parent, unordered_map<string, int> &size, string a, string b) {
	a = find(parent, a)
	, b = find(parent, b);

	if (a != b) {
		parent[a] = b;
		size[b] += size[a];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int f;
		cin >> f;
		vector<pair<string, string>> input(f);
		unordered_map<string, string> parent;
		unordered_map<string, int> size;

		for (auto &[a, b] : input) {
			cin >> a >> b;
			parent[a] = a, parent[b] = b
			, size[a] = 1, size[b] = 1;
		}

		for (auto &[a, b] : input) {
			merge(parent, size, a, b);
			cout << size[find(parent, a)] << '\n';
		}
	}
}