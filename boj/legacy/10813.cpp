#include <iostream>
#include <vector>

using namespace std;

int main() {
    short i, j, n, m, temp;
    cin >> n >> m;
    vector<short> result(n);

    for (short l = 1; l <= n; ++l)
        result[l-1] = l;

    for (short l = 0; l < m; ++l) {
        cin >> i >> j;
        i--, j--;
        temp = result[i]
        , result[i] = result[j]
        , result[j] = temp;
    } for (short l = 0; l < n; ++l)
        cout << result[l] << ' ';

}