#include <iostream>

using namespace std;

int main() {
    int input, divideTo = 1;
    cin >> input;

    while (input > 1) {
        for (int i = 2; input % i != 0; ++i)
            divideTo = i;
        cout << divideTo+1 << endl;
        input /= divideTo+1;
    }
}