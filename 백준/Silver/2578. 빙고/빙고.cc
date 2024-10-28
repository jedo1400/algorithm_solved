#include <iostream>
#include <vector>

using namespace std;

bool bingo(vector<vector<short>> &array, short n) {
    short bingo{};
    bool flag{};

    for (auto &i : array) {
        for (auto &j : i)
            if (j == n) {
                j = 0, flag = 1;
                break;
            }
        if (flag) break;
    }
    
    bool comp[2] = {1, 1};
    for (short i = 0; i < 5; ++i) {
        if (array[i][i]) comp[0] = 0;
        if (array[i][4-i]) comp[1] = 0;

        bool comp[2] = {1, 1};
        for (short j = 0; j < 5; ++j) { // 세로
            if (array[j][i]) comp[0] = 0;
            if (array[i][j]) comp[1] = 0;
        }

        if (comp[0]) ++bingo;
        if (comp[1]) ++bingo;
    }
    
    if (comp[0]) ++bingo;
    if (comp[1]) ++bingo;

    if (bingo >= 3)
        return 1;
    return 0;
}

int main() {
    vector<vector<short>> array(5, vector<short>(5));
    short result{};

    for (auto &i : array)
        for (auto &j : i)
            cin >> j;
    
    for (short i = 0; i < 25; ++i) {
        short n;
        cin >> n;
        if (!result && bingo(array, n))
            result = i+1;
    }

    cout << result;
}