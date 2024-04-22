#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n, v, c = 0;
    cin >> n;
    vector<short> array(n);
    for (short i = 0; i < n; ++i)
        cin >> array[i];
    cin >> v;
    for (short i = 0; i < n; ++i)
        if (array[i] == v)
            c++;
    cout << c;
}