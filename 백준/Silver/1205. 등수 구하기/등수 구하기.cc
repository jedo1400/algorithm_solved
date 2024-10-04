
#include <iostream>

using namespace std;

int main() {
    int n, s, p, result = 1;
    cin >> n >> s >> p;

    if (!n) {
        cout << 1;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        int score;
        cin >> score;
        if (score < s) {
            cout << result;
            return 0;
        }
        else if (score == s)
            continue;
        ++result;
    }

    if (n < p)
        cout << result;
    else
        cout << -1;
}