#include <iostream>
#define uint unsigned int

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    uint s;
    cin >> s;

    long long n = 0, cur = 1;
    while (n < s)
        n += cur, ++cur;

    if (n > s)
        --cur;
    cout << cur-1;
}