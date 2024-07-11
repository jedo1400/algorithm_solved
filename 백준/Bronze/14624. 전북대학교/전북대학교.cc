#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    
    if (n % 2) {
        for (short i = 0; i < n; ++i)
            cout << '*';
        cout << '\n';
        for (short i = 1; n/2+i <= n; ++i) {
            for (short j = 1; j <= n/2+i; ++j)
                if (j == n/2+i || j == n/2-i+2)
                    cout << '*';
                else
                    cout << ' ';
            cout << '\n';
        }
    }
    else
        cout << "I LOVE CBNU";
}