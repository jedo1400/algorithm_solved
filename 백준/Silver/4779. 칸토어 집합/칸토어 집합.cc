#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

vector<int> memoization(short n) {
    vector<int> memo;
    for (short i = 0; i <= n; ++i)
        memo.push_back(pow(3, i));
    return memo;
}

deque<bool> cantor_set(const short n, vector<int> &memo) {
    // static vector<int> memo = memoization(n);
    int m = memo[n], o = m/3;
    static deque<bool> result(m, 1);
    static int size = n;

    if (n) {
        for (int i = o; i < o*2; ++i)
            result[i] = 0;
        return cantor_set(n-1, memo);
    }

    for (short i = 2; i <= size; ++i)
        for (int j = 0, k = memo[i]/3*2; k < memo[i]; ++j, ++k)
            result[k] = result[j];

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> memo = memoization(12);
    deque<bool> result = cantor_set(12, memo);

    short n;
    while (!cin.eof() && cin >> n) {
        for (int i = 0; i < memo[n]; ++i)
            cout << (result[i] ? '-' : ' ');
        cout << '\n' << flush;
    }
}