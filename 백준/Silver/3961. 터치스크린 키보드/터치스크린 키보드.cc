#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

char keyboard[3][10] = { { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' }
						, { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0 }
						, { 'z', 'x', 'c', 'v', 'b', 'n', 'm', 0, 0, 0 } };

vector<pair<int, int>> memo(26, {-1, 0});

pair<int, int> position(char &c) {
	if (memo[c-'a'].first == -1)
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 10 && keyboard[i][j]; ++j)
				if (keyboard[i][j] == c)
					memo[c-'a'] = {i, j};
	
	return memo[c-'a'];		
}

int abs(int n) {
	return n < 0 ? -n : n;
}

int dist(string &a, string &b) {
	int result = 0;

	for (int i = 0; i < a.length(); ++i) { // 단어는 사용자가 입력한 단어와 길이가 모두 같다
		pair<int, int> ap = position(a[i])
					 , bp = position(b[i]);
		
		result += abs(ap.first - bp.first) + abs(ap.second - bp.second);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string a;
		int l;
		cin >> a >> l;
		vector<pair<string, int>> result(l);

		for (auto &[b, d] : result) {
			cin >> b;
			d = dist(a, b);
		}

		sort(result.begin(), result.end()
		, [](pair<string, int> &a, pair<string, int> &b) -> bool {
			if (a.second != b.second)
				return a.second < b.second;
			return a.first < b.first;
		});

		for (auto &[b, d] : result)
			cout << b << ' ' << d << '\n';
	}
}