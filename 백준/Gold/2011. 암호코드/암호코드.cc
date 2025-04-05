#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int dp[5001];
	dp[0] = 1, dp[1] = 1;

	if (!(str[0]-48)) { // 암호는 1~26의 숫자
		cout << 0; 
		return 0;
	}

	for (int i = 2; i <= str.length(); ++i) {
		int f = str[i-2]-48, s = str[i-1]-48;

		// 해독이 불가능한 경우들
		if ((!f && !s) || (!s && f*10 + s > 26)) {
			cout << 0; 
			return 0;
		}

		// s가 0인 경우 (이 시점에서 f는 1 또는 2)
		if (!s)
			dp[i] = dp[i-2];

		// f가 0이 아니고 fs가 26 이하인 경우
		else if (f && f*10 + s <= 26)
			dp[i] = (dp[i-1] + dp[i-2]) % 1000000;

		// 나머지 경우(한 자리 숫자로만 해독 가능)
		else
			dp[i] = dp[i-1];
	}

	cout << dp[str.length()];
}