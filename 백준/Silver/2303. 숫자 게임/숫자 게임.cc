#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> cards(n, vector<int>(5));

    for (auto &i : cards)
        for (auto &j : i)
            cin >> j;
    
    int which, point{};
    for (int i{}; i < n; ++i)
        for (int j{}; j < 5; ++j)
            for (int k = j+1; k < 5; ++k)
                for (int l = k+1; l < 5; ++l) {
                    int sum = (cards[i][j] + cards[i][k] + cards[i][l]) % 10;
                    if (point <= sum)
                        point = sum, which = i+1;
                }

    cout << which;
}