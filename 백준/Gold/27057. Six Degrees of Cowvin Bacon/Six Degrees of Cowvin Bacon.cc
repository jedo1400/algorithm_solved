#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MAX_N 300
#define MAX_M 10000

int n, m;
vector<vector<int>> c(MAX_N+1, vector<int>()) // c[n] == n번 영화에 출연한 소들
                    , v(MAX_M+1, vector<int>()); // v[n] == n번 소가 출연한 영화들

vector<vector<double>> d;

int floyd_warshall() {

    for (int i = 1; i <= n; ++i) { // init
        d[i][i] = 0;
        
        for (auto &j : v[i])
            for (auto &k : c[j])
                if (i != k)
                    d[i][k] = 1, d[k][i] = 1;
    }
    
    for (int m = 1; m <= n; ++m)
        for (int s = 1; s <= n; ++s)
            for (int e = 1; e <= n; ++e)
                d[s][e] = min(d[s][e], d[s][m] + d[m][e]);

    int result = INF;

    for (int i = 1; i <= n; ++i) {
        int sum = 0;

        for (int j = 1; j <= n; ++j)
            if (i != j)
                sum += d[i][j];
        
        result = min((double)result, (double)(sum)/(n-1) * 100);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    d = vector(n+1, vector<double>(n+1, INF));

    for (int i = 1; i <= m; ++i) {
        int o;
        cin >> o;

        while (o--) {
            int p;
            cin >> p;
            c[i].push_back(p);
            v[p].push_back(i);
        }
    }

    cout << floyd_warshall();
}