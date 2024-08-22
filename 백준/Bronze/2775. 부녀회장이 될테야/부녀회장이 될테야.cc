#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int array[15][15]{0,};

    for (short i = 1; i <= 14; ++i) // 0층 초기화
        array[0][i] = i;

    for (short i = 1; i <= 14; ++i) // 계산할 층
        for (short j = 1; j <= 14; ++j) // 계산할 호실
            for (short k = 1; k <= j; ++k)
                array[i][j] += array[i-1][k];

    int t;
    cin >> t;
    
    while (t--) {
        short k, n;
        cin >> k >> n;
        cout << array[k][n] << '\n';
    }
}