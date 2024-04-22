#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a = 1, b = 1;
    while(a && b) {
        cin >> a >> b;
        if (a && a)
            cout << (a > b ? "Yes" : "No") << '\n';
    }
}