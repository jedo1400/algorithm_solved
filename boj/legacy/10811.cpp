#include <iostream>
#include <vector>

using namespace std;

int main() {
    short i, j, n, m, temp;
    cin >> n >> m;

    vector<short> array(n+1);

    for (short k = 1; k <= n; ++k)
        array[k] = k;

    for (short k = 0; k < m; ++k) {
        cin >> i >> j;
        for (short l = 0; l < (j-i+1)/2; ++l)
            temp = array[i+l]
            , array[i+l] = array[j-l]
            , array[j-l] = temp;
    }

    for (short k = 1; k <= n; ++k)
        cout << array[k] << ' ';
}