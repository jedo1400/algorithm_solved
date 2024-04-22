#include <iostream>
#include <string>

using namespace std;

int main() {
    string array[5];
    for (short i = 0; i < 5; ++i)
        cin >> array[i];
    for (short j = 0; j < 15; ++j)
        for (short i = 0; i < 5; ++i)
            if (j+1 <= array[i].size())
                cout << array[i][j];
}