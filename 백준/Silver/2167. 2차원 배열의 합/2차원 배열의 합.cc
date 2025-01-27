#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> array(n, vector<int>(m, 0));
    vector<vector<int>> prefix_sum = array;
    
    for (int i{}; i < n; ++i)
        for (int j{}; j < m; ++j) {
            cin >> array[i][j];
            prefix_sum[i][j] = array[i][j];
            if (j) prefix_sum[i][j] += prefix_sum[i][j-1];
        }
    
    for (int i = 1; i < n; ++i)
        for (int j{}; j < m; ++j)
            prefix_sum[i][j] += prefix_sum[i-1][j];
    
    int k;
    cin >> k;

    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> y >> x;
        --i, --j, --x, --y; 
        cout << prefix_sum[y][x] - (i ? prefix_sum[i-1][x] : 0) - (j ? prefix_sum[y][j-1] : 0) + (i && j ? prefix_sum[i-1][j-1] : 0) << '\n';
    }
}