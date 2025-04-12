#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	cout << (n % 2 ? "SK" : "CY");
	
	// int dp[1000] = {0,};

	// dp[1] = 1
	// , dp[2] = 0
	// , dp[3] = 1;

	// for (int i = 4; i < 1000; ++i)
	// 	dp[i] = !(dp[i-1] && dp[i-3]);
	
	// for (int i = 0; i < 1000; ++i)
	// 	cout << dp[i] << '\n';
}