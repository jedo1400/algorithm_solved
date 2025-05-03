#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define LL long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    LL total = 0;
    cin >> n >> m;
    vector<vector<LL>> sum(n+1, vector<LL>(m+1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            bool t;
            cin >> t;
            total += t;
            
            sum[i][j] = t + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }

    LL smallest = 0;
    vector<LL> arr(m+1); // 비용에 대한 기여도 작을 수록 좋음

    for (int t = 1; t <= n; ++t) {
        for (int b = t; b <= n; ++b) {
            int h = b - t + 1; // 높이

            for (int j = 1; j <= m; ++j) // 최적인 열 찾기
                arr[j] = h - 2 * (sum[b][j] - sum[t-1][j] - sum[b][j-1] + sum[t-1][j-1]);

            LL candidate = arr[1], cur = arr[1];

            // 최소 연속부분합
            for(int j = 2; j <= m; ++j)
                cur = min(arr[j], cur + arr[j])
                , candidate = min(candidate, cur);

            smallest = min(smallest, candidate);
        }
    }

    cout << smallest + total << "\n";
}