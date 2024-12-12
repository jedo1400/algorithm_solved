#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool dp[15][4] = { {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}
                     , {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}
                     , {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 1}
                     , {1, 0, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}
                     , {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1} };

    int index[28] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    int n;
    cin >> n;
    
    while (n--) {
        int m;
        cin >> m;
        for (int i{}; i < 4; ++i)
            cout << (dp[index[(m-1)%28]][i] ? "딸기" : "V");
        cout << '\n';
    }
}