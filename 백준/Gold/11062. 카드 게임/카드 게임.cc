#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// l과 r 사이의 카드만으로 게임을 했을때 근우의 점수의 최대값을 반환하는 함수
int sol(vector<int> &cards, vector<vector<int>> &dp, int l, int r, bool turn = 0) {
	if (l > r) return 0; // l == r인 경우 고려
	if (dp[l][r] != -1) return dp[l][r];

	if (!turn) // 근우의 차례인 경우
		return dp[l][r] = max(sol(cards, dp, l+1, r, 1) + cards[l], sol(cards, dp, l, r-1, 1) + cards[r]);
		// 좌, 우측 카드 중 근우에게 가장 이득인 카드뽑기
	else // 명우의 차례인 경우
		return dp[l][r] = min(sol(cards, dp, l+1, r, 0), sol(cards, dp, l, r-1, 0));
		// 명우는 근우가 최소한의 점수만 얻도록 해야함(=자신의 차례에 가장 이득인 카드 뽑기)
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector<int> cards(n);
		vector<vector<int>> dp(n, vector<int>(n, -1));
		for (auto &i : cards)
			cin >> i;
		
		cout << sol(cards, dp, 0, n-1) << '\n';
	}
}