#include <iostream>

using namespace std;

int main() {
	int dp[1001] = {0, 1, 3};
	for (short i = 3; i <= 1000; ++i)
		dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;

	short n;
	cin >> n;
	cout << dp[n];
}
