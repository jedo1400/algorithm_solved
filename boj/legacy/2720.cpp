#include <iostream>

using namespace std;

int main() {
    short cent;
    short n;
    short change[4] = {0,};

    cin >> n;

    for (short i = 0; i < n; ++i) {
        cin >> cent;
    
        while (cent >= 25)
            cent -= 25, change[0]++;
        while (cent >= 10)
            cent -= 10, change[1]++;
        while (cent >= 5)
            cent -= 5, change[2]++;
        while (cent >= 1)
            cent -= 1, change[3]++;

        for (short i = 0; i < 4; ++i) {
            cout << change[i] << ' ';
            change[i] = 0;
        } cout << endl;
    }
}