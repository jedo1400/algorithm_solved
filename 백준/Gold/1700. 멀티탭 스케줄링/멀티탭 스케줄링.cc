#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define PII pair<int, int>

int next(vector<int> &v, int n, int from) {
	for (int i = from; i < v.size(); ++i)
		if (v[i] == n)
			return i;

	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(k), socket(n, -1);

	for (auto &i : v)
		cin >> i;

	int result{};
	for (int i = 0; i < k; ++i) {
		PII candidate = {0, INT_MIN};

		if (next(socket, v[i], 0) != INT_MAX) // 이미 꽂혀있다면
			continue;

		for (int j = 0; j < n; ++j) {
			if (socket[j] == -1) { // 빈 소켓이라면
				candidate = {j, -1};
				break;
			}
			
			int ns = next(v, socket[j], i+1); // 다음 스케쥴
			if (candidate.second < ns)
				candidate = {j, ns};
		}

		socket[candidate.first] = v[i];

		if (candidate.second != -1) // 빈 소켓에 꽂은게 아니라면
			++result;
	}

	cout << result;
}