#include <iostream>

using namespace std;

int main() {
    short a, b;
    while (1) {
        cin >> a >> b;
        if (a == b && a == 0)
            break;
        if (b % a == 0) cout << "factor";
        else if (a % b == 0) cout << "multiple";
        else cout << "neither" ;
        cout << endl;
    }
}