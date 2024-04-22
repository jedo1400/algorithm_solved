#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n, m, tmp;
    cin >> n >> m;
    vector<vector<short>> array(n, vector<short> (m, 0));

    for (short i = 0; i < 2; ++i) {
        for (short j = 0; j < n; ++j)
            for (short k = 0; k < m; ++k) {
                cin >> tmp;
                array[j][k] += tmp;
            }
    }

    for (short j = 0; j < n; ++j) {
        for (short k = 0; k < m; ++k)
            cout << array[j][k] << ' ';
        cout << endl;
    }
}