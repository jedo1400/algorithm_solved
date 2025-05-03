#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    int n, m, total = 0;
    cin >> n >> m;
    vector<vector<int>> sum(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            bool t;
            cin >> t;
            total += t;
            
            sum[i][j] = t + sum[i][j-1];
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i][j] += sum[i-1][j];

    int result = 1e9;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; i+k <= n; ++k)
                for (int l = 0; j+l <= m; ++l) {
                    int mc = j+l, mr = i+k
                        , prefix_sum = sum[mr][mc] - sum[i-1][mc] - sum[mr][j-1] + sum[i-1][j-1];
                    
                    result = min(result, (k+1)*(l+1) + total - prefix_sum * 2);
                }

    cout << result;
}