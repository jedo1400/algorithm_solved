#include <algorithm>
#include <iostream>
#include <unistd.h>

using namespace std;

#define MAX 100000
#define INF 1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s
        , og[MAX+1]{0,}
        , sum[MAX+1]{0,};
    cin >> n >> s;

    for (int i = 1; i <= n; ++i) {
        cin >> og[i];
        sum[i] += sum[i-1] + og[i];
    }
    
    int shortest = INF
        , start = 1, end = 1;

    while (start <= n && end <= n) {
        if (sum[end] - sum[start] + og[start] >= s) {
            shortest = min(shortest, end-start+1);
            ++start;
        }

        else
            ++end;
    }

    cout << (shortest == INF ? 0 : shortest);
}
