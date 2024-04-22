#include <iostream>
#include <vector>

using namespace std;

int main() {
    short n, x;
    cin >> n >> x;
    vector<short> a(n);

    for (short i = 0; i < n; ++i)
        cin >> a[i];
    
    for (short i = 0; i < n; ++i)
        if (a[i] < x)
            cout << a[i] << ' ';
}