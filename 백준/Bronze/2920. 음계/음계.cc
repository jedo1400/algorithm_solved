#include <iostream>

using namespace std;

int main() {
    short n;
    bool flag[2] = {1, 1}; // ascending, descending
    for (short i = 0; i < 8; ++i) {
        cin >> n;
        if (n != i+1)
            flag[0] = 0;
        if (n != 8-i)
            flag[1] = 0;
    }
    
    if (flag[0]) cout << "ascending";
    else if (flag[1]) cout << "descending";
    else cout << "mixed";
}