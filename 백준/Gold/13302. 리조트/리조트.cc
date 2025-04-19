#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX 100
#define INF 1e9

int n, m;
bool unnecessary[MAX + 1]{0,};
vector<vector<int>> dp(MAX + 1, vector<int>(51, INF));

int solve(int day = 1, int coupon = 0) {
	static tuple<int, int, int> type[3] = { {1, 10000, 0}, {3, 25000, 1}, {5, 37000, 2} };
	// dp[i][j] = i 날짜, j 가진 쿠폰 수

	if (day > n) return 0; // 종료조건
	if (dp[day][coupon] != INF) return dp[day][coupon];
	if (unnecessary[day]) return dp[day][coupon] = solve(day+1, coupon); // 리조트에 가지 못하는 날에 예매할 필요는 없음

	for (int i = 0; i < 3; ++i) {
		auto &[l, p, c] = type[i];
		dp[day][coupon] = min(dp[day][coupon], solve(day + l, coupon + c) + p);
	}

	if (coupon >= 3) // 쿠폰 쓸 수 있다면 쓰기
		dp[day][coupon] = min(dp[day][coupon], solve(day+1, coupon-3));

	return dp[day][coupon];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int o;
		cin >> o;
		unnecessary[o] = 1;
	}

	cout << solve();
}