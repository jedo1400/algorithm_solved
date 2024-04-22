#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;
    for (short i = 0; i < n/4; ++i)
        cout << "long ";
    cout << "int";
}