#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    for (short i = 1; i < n * 2; ++i) {
        if (i <= n)
            for (short j = n; j > 0; --j)
                cout << (j <= i ? '*' : ' ');
        else
            for (short j = 1; j <= n; ++j)
                cout << (i - n < j ? '*' : ' ');
        cout << endl;
    }

}