#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define MAX 100
#define PII pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<PII> p(n); // p[번호] = {소모 체력, 기쁨}

    for (auto &i : p) 
        cin >> i.first;

    for (auto &i : p)
        cin >> i.second;

    sort(p.begin(), p.end());

    vector<int> dp(MAX); // dp[n] = 세준이가 체력 n만큼을 썼을때 얻을 수 있는 최대 기쁨

    for (auto &[h, d] : p)
        for (int i = MAX-1; i-h >= 0; --i)
            dp[i] = max(dp[i], dp[i-h] + d);
    
    cout << dp[MAX-1];
}