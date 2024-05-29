#include <iostream>
#include <vector>

using namespace std;

int main() {
    short i, j, k, n, m;
    cin >> n >> m;
    vector<short> result(n, 0);

    for (short l = 0; l < m; ++l) {
        cin >> i >> j >> k;
        for (short o = i; o <= j; ++o)
            result[o-1] = k;
    } for (short l = 0; l < n; ++l)
        cout << result[l] << ' ';

}