#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int square[1001];
	for (int i = 1; i <= 1000; ++i)
		square[i] = i*i;

	bool dp[1000001]{0,}; // 구사과가 이길 수 있는가
	dp[1] = 1;

	for (int i = 2; i <= 1000000; ++i) {
		bool flag = 0;

		for (int j = 1; square[j] <= i; ++j)
			if (!dp[i-square[j]]) {
				flag = 1;
				break;
			}
		
		dp[i] = flag;
	}
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n] ? "koosaga" : "cubelover") << '\n';
	}
}
