#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> DP(n+1);

    DP[1] = 0, DP[2] = 1, DP[3] = 1;

    for (int i = 4; i <= n; ++i) {
        DP[i] = DP[i-1] + 1; // -1, 연산횟수 +1
        if (!(i % 3)) DP[i] = min(DP[i], DP[i/3] + 1);
        if (!(i % 2)) DP[i] = min(DP[i], DP[i/2] + 1); 
    }

    cout << DP[n];
}