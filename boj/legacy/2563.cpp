#include <iostream>

using namespace std;

int main() {
    bool array[100][100] = {0,};
    short n, x, y, area = 0;

    cin >> n;
    for (short i = 0; i < n; ++i) {
        cin >> x >> y;
        for (short j = 0; j < 10; ++j)
            for (short k = 0; k < 10; ++k)
                array[x + k][y + j] = 1;
    }

    for (short j = 0; j < 100; ++j)
        for (short k = 0; k < 100; ++k)
            if (array[k][j])
                area++;
    
    cout << area;
}