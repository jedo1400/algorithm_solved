#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define PII pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
	cin >> n >> t;
	vector<PII> prob(n);
	vector<int> dp(t+1, 0);

	int sum{};
	for (auto &[d, m] : prob) {
		cin >> d >> m;
		sum += m;
	}
	
	for (auto &[d, m] : prob)
		for (int i = t; i >= d; --i)
			dp[i] = max(dp[i], dp[i-d] + m);
	
	cout << sum - dp[t];
}