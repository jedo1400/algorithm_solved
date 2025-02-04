#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int abs(int n) { return n < 0 ? -n : n; }

bool isIncludingBrokenNum(int n, bool* broken) {
    if (!n && broken[0]) return 1;

    while (n) {
        if (broken[n % 10])
            return 1;
        n /= 10;
    }

    return 0;        
}

int intlen(int n) {
    if (!n) return 1;

    int result = 0;
    for (int i = n; i; i /= 10)
        ++result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    bool broken[10] = {0,};

    for (int i{}; i < m; ++i) { // 고장난 버튼들 입력받기
        int o;
        cin >> o;
        broken[o] = 1;
    }

    vector<int> candidate = { 100 };
    for (int i = 0; i < 1000000; ++i)
        if (!isIncludingBrokenNum(i, broken))
            candidate.push_back(i);

    int min_diff = INT_MAX;
    for (int i{}; i < candidate.size(); ++i) {
        int diff = abs(n-candidate[i]);

        // 수빈이가 지금 보고 있는 채널은 100번이다.
        if (i) diff += intlen(candidate[i]);

        min_diff = min(min_diff, diff);
    } cout << min_diff;
}