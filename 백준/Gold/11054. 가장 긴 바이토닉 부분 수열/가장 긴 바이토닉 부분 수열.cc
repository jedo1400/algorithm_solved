#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
	cin >> n;
	vector<int> v(n), inc(n, 1), dec(n, 1);

	for (auto &i : v)
		cin >> i;

	for (int i = 1; i < n; ++i) { // 가장 긴 증가하는 부분 수열
		int p = -1;

		for (int j{}; j < i; ++j)
			if (v[j] < v[i] && inc[p] < inc[j])
				p = j;
		
		inc[i] += (p == -1 ? 0 : inc[p]);
	}

	int result = 1;
	for (int i = n - 2; i >= 0; --i) { // 가장 긴 감소하는 부분 수열
		int p = -1;

		for (int j = i + 1; j < n; ++j)
			if (v[j] < v[i] && dec[p] < dec[j])
				p = j;
		
		dec[i] += (p == -1 ? 0 : dec[p])
		, result = max(result, dec[i] + inc[i] - 1);
	}

	cout << result;
}