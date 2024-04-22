#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short n;
    cin >> n;

    for (short i = 1; i <= n; ++i) {
        for (short j = 0; j < i; ++j)
            cout << '*';
        cout << endl;
    }
}