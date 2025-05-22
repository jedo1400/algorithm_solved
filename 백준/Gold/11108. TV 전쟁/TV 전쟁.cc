#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define MAX 10080
#define PII pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n; // <= 1e6
        cin >> n;
        vector<vector<PII>> v(MAX+1, vector<PII>()); // 티비 프로그램들, v[종료시간] = {시작시간, 선호도}

        while (n--) {
            int s, d, p;
            cin >> s >> d >> p;
            v[s+d].emplace_back(s, p);
        }

        vector<int> dp(MAX+1, 0);
        
        for (int e = 1; e <= MAX; ++e) {
            dp[e] = max(dp[e], dp[e-1]); 

            for (auto &[s, p] : v[e])
                dp[e] = max(dp[e], dp[s] + p);
        }

        cout << dp[MAX] << '\n';
    }
}