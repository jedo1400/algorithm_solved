#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stair(n+1, 0), dp(n+1, 0);

    for (int i = 1; i <= n; ++i)
        cin >> stair[i];

    dp[1] = stair[1]
    , dp[2] = stair[1] + stair[2] // 계단에 적혀있는 수는 300보다 작은 자연수이므로 두 계단의 합이 stair[1]보다 작을 수 없음
    , dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]); // 1번째에서 건너뛰어 3번째 계단에 갔을때와 첫 계단을 건너뛰고 2번째 계단에서 3번째 계단으로 간 경우
    
    for (int i = 4; i <= n; ++i)
        dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
        // stair[1] + stair[3]의 일반화, 계단을 전전 계단에서 건너뛰어 지금 계단에선 연속해서 올라갈 수 있을때를 비교
    
    cout << dp[n];
}