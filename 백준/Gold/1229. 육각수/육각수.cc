#include <algorithm>
#include <iostream>

#define MAX 1000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1000]= { 0, 1 };
    for (int i = 2; i < 1000; ++i)
        dp[i] = dp[i-1] + i*2 + (i-2) * 2 + 1;


    int dp2[MAX+1] = { 0 };
    for (int i = 1; i <= MAX; ++i) dp2[i] = 6;

    for (int i = 1; i <= MAX; ++i)
        for (int j = 1; dp[j] <= i; ++j)
            dp2[i] = min(dp2[i], dp2[i-dp[j]] + 1);

    int n;
    cin >> n;
    cout << dp2[n];
}