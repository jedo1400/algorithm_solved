#include <iostream>

using namespace std;

#define uint unsigned int

uint lake[2001][2001]{0,}
    , dp[2001][2001]{0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> lake[i][j];
            lake[i][j] += lake[i-1][j];
        }

    for (int i = 1; i <= 2000; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = dp[i-1][j-1] + lake[i][j];

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << dp[a][b] << '\n';
    }
}