#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	cout << (!(n % 5) || n % 5 == 2 ? "CY" : "SK");

	// int dp[100]{0,}; // 상근이가 게임에서 이길 수 있는가

	// dp[1] = 1
	// , dp[2] = 0
	// , dp[3] = 1;

	// for (int i = 4; i < 100; ++i) {
	// 	bool flag = 0;  // 상근이가 이길 수 없다고 가정

	// 	for (int j = 1; j <= i; j *= 4)
	// 		if (!dp[i-j]) {  // 상근이가 질 수밖에 없는 이전턴이 있다면
	// 			flag = 1;  // 현재 턴의 상근이는 이길 수 있다
	// 			break;
	// 		}

	// 	dp[i] = flag;
	// }


	// for (int i = 1; i < 100; ++i)
	// 	cout << i << ' ' << (dp[i] ? "SK" : "CY") << '\n';
}