#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cout << '*';
        cout << '\n';
    }
}