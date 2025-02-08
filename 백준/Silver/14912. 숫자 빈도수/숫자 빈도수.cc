#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, count[100001] = {0,};
    cin >> n >> d;

    for (int i = 1; i <= n; ++i)
        for (int j = i; j; j /= 10)
            ++count[j % 10];

    cout << count[d];
}