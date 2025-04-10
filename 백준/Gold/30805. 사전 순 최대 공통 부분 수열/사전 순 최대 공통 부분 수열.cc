#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define PII pair<int, int>
#define TIII tuple<int, int, int>

struct cmp { // https://paris-in-the-rain.tistory.com/68
	bool operator()(PII &a, PII &b) {
		if (a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n;
	priority_queue<PII, vector<PII>, cmp> a;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		a.push({t, i});
	}

	cin >> m;
	priority_queue<PII, vector<PII>, cmp> b;
	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		b.push({t, i});
	}

	vector<TIII> result;

	// 양 수열 최대값 맞추기
	bool flag = 1;
	while (!a.empty() && !b.empty() && 1) {
		while (flag && a.top().first != b.top().first) {
			while (a.top().first > b.top().first) {
				if (a.empty()) {
					flag = 0;
					break;	
				}
				a.pop();
			}
			
			while (b.top().first > a.top().first) {
				if (b.empty()) {
					flag = 0;
					break;
				}
				b.pop();
			}

		}

		if (!flag)
			break;

		if (a.top().first != b.top().first)
			break;

		if (result.empty() || a.top().second > get<1>(result.back()) && b.top().second > get<2>(result.back())) {
			result.push_back({a.top().first, a.top().second, b.top().second});
			a.pop();
			b.pop();	
		}

		else if (a.top().second < get<1>(result.back()))
			a.pop();
		
		else if (b.top().second < get<2>(result.back()))
			b.pop();
	}
	
	cout << result.size() << '\n';
	for (auto &i : result)
		cout << get<0>(i) << ' ';
}