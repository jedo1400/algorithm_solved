#include <iostream>

using namespace std;

int main() {
    bool array[100][100]{0,};
    short n, width{}, length{};
    cin >> n;

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < n; ++j) {
            char tmp;
            cin >> tmp;
            array[i][j] = tmp == '.' ? 0 : 1;
        }
    
    for (short i = 0; i < n; ++i) {
        bool flag{};
        for (short j = 1; j < n; ++j) {
            if (array[i][j])
                flag = 0;
            else if (!array[i][j] && !array[i][j-1] && !flag)
                flag = 1, ++width;
        }
    }
    
    for (short i = 0; i < n; ++i) {
        bool flag{};
        for (short j = 1; j < n; ++j) {
            if (array[j][i])
                flag = 0;
            else if (!array[j][i] && !array[j-1][i] && !flag)
                flag = 1, ++length;
        }
    }
    
    cout << width << ' ' << length;
}