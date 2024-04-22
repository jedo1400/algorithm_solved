#include <iostream>
#include <vector>

using namespace std;

int main() {
    bool arr[30] = {0,};
    short small = -1, large, buff;
    
    for (short i = 0; i < 28; ++i) {
        cin >> buff;
        arr[buff-1] = 1;
    }

    for (short i = 0; i < 30; ++i) {
        if (arr[i] == 0) {
            large = i+1;
            if (small == -1)
                small = i+1;
        }
    } cout << small << endl << large;
}