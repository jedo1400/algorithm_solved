#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 물품의 수, 배낭이 버틸 수 있는 무게
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> item(n); // {무게, 가치}
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (auto &i : item)
        cin >> i.first >> i.second;

    // 정렬안하는 경우 반례:
    // 4 5
    // 1 100
    // 2 90
    // 3 80
    // 4 200
    sort(item.begin(), item.end(), 
    [](pair<int, int> &a, pair<int, int> &b) -> bool {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    });

    for (int i = 1; i <= n; ++i) {
        auto [weight, value] = item[i-1];

        for (int j = 1; j <= k; ++j) {
            if (weight <= j) // 만약 물건의 무게보다 배낭이 버틸 수 있는 무게가 크다면
                dp[i][j] = max(dp[i-1][j], value + dp[i-1][j-weight]);
                // dp[i-1][j] = 현재 물건(item[i-1])을 고려하지 않은 최대 가치와,
                // 현재 물건을 고려한 가치 + 현재 물건만큼의 무게를 뺀 현재 물건의 가치를 고려하지 않은 최대 가치를 비교하여 대입
            
            else // 만약 물건의 무게를 배낭이 버틸 수 없다면
                dp[i][j] = dp[i][j-1];
                // 이전 배낭(최대 버틸 수 있는 무게-1)의 최대 가치를 대입
        }
    }

    cout << dp[n][k];

    // dp 배열 시각화
    // for (int i = 1; i <= k; ++i)
    //     cout << '\t' << i;
    // cout << '\n';
    
    // for (int i = 1; i <= n; ++i) {
    //     cout << '(' << item[i-1].first << ", " << item[i-1].second << ")\t";
    //     for (int j = 1; j <= k; ++j)
    //         cout << dp[i][j] << '\t';
    //     cout << '\n';
    // }
}