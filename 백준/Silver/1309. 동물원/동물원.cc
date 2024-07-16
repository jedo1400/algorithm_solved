#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<long long> memo(n+1);
    memo[0] = 1, memo[1] = 3;

    for (int i = 2; i <= n; ++i)
        memo[i] = (memo[i-1]*2 + memo[i-2]) % 9901;

    cout << memo[n];
}