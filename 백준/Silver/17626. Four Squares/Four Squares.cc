#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> square(224), dp(50001);
    for (int i = 1; i <= 223; ++i) // 223^2 = 49729
        square[i] = i*i, dp[square[i]] = 1;

    for (int i = 2; i <= 50000; ++i) {
        if (dp[i] == 1) // 제곱수인 경우
            continue;
        
        int smallest = 50000;
        // for (int j = 1, k = i-1; j <= i/2; ++j, --k) {
        //     smallest = min(smallest, result[j] + result[k]);

        for (int j = 1; square[j] <= i  && j <= 223; ++j)
            smallest = min(smallest, dp[square[j]] + dp[i-square[j]]);
        
        dp[i] = smallest;
    }

    int n;
    cin >> n;
    cout << dp[n];
}