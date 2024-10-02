#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> doFlattening(vector<vector<short>> &array, int left_block, short highest_pos) {
    pair<int, int> result = make_pair(INT_MAX, -1); // f = 시간, s = 높이

    for (short i = 0; i <= highest_pos; ++i) {
        int time{}, inv = left_block;
        bool isCompleted = 1;

        for (auto &j : array) // 부수기
            for (auto &k : j)
                if (k > i) {
                    short diff = k-i;
                    inv += diff, time += diff * 2;
                }


        for (auto &j : array) {
            for (auto &k : j) {
                short diff = i-k;

                if (k < i) {
                    if (inv >= diff)
                        inv -= diff, time += diff;
                    else {
                        isCompleted = 0;
                        break;
                    }
                }
            }
            if (!isCompleted)
                break;
        }
        
        if (isCompleted && time <= result.first && i > result.second)
            result.first = time, result.second = i;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m, highest{};
    int b; // 가진 블록 수
    cin >> n >> m >> b;
    vector<vector<short>> array(n, vector<short>(m));

    for (auto &i : array)
        for (auto &j : i) {
            cin >> j;
            if (highest < j) highest = j;
        }
    
    pair<int, int> result = doFlattening(array, b, highest);
    cout << result.first << ' ' << result.second;
}