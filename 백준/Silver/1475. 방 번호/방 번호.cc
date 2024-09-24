#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int type[9] = {0,};
    cin >> n;
    
    for (auto &i : n) {
        if (i-48 == 9) ++type[6];
        else ++type[i-48];
    }
    
    int largest{}, idx;
    for (int i = 0; i < 9; ++i)
        if (type[i] > largest || (type[i] == largest && idx == 6))
            largest = type[i], idx = i;

    if (idx == 6)
        cout << largest/2 + (largest%2 ? 1 : 0);
    else
        cout << largest;
}
