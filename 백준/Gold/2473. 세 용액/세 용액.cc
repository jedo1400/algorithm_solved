#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define TIII tuple<int, int, int>

long _abs(long n) {
    return n > 0 ? n : -n;
}

TIII two_pointer(vector<int> &v) {
    long best = 1e9*3;
    TIII result = { -1, -1, -1 }; // i < l < r이 보장됨

    for (int i = 0; i < v.size()-2; ++i) {

        int l = i+1
            , r = v.size()-1;

        while (l < r) {
            long sum = (long)v[i] + v[l] + v[r];

            if (_abs(sum) < best)
                best = _abs(sum), result = {i, l, r};

            if (sum > 0)
                --r; // 값 줄이기
            else if (sum < 0)
                ++l; // 값 늘리기
            else // 0이면
                return result;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> solution(n); // 용액
    
    for (auto &i : solution)
        cin >> i;

    sort(solution.begin(), solution.end());

    auto [a, b, c] = two_pointer(solution);
    cout << solution[a] << ' ' << solution[b] << ' ' << solution[c];
}