#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF (unsigned int)(1 << 31) - 1

using namespace std;

string concat(string &a, string &b) {
	for (int i = 0; i < a.length(); ++i) {
		bool comp = 1;
		int size;

		for (size = 0; i + size < a.length() && size < b.length(); ++size)
			if (a[i+size] != b[size]) {
				comp = 0;
				break;
			}
		
		if (comp)
			return a + b.substr(size);
	}

	return a+b;
}

int solve(vector<string> &v) {
	static int result = INF;
	static bool visited[7]{0,}; // 2 <= n <= 7
	static vector<int> combi;

	if (combi.size() == v.size()) {
		string t = v[combi[0]];
		for (int i = 1; i < combi.size(); ++i)
			t = concat(t, v[combi[i]]);
	
		result = min(result, (int)t.length());
	}

	else {
		for (int i = 0; i < v.size(); ++i)
			if (!visited[i]) {
				visited[i] = 1;
				combi.push_back(i);
				solve(v);
				visited[i] = 0;
				combi.pop_back();
			}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v(n);

	for (auto &i : v)
		cin >> i;
	
	cout << solve(v);
}