#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long fact[10001] = {1};
    
    for (int i = 1; i <= 10000; ++i) {
        fact[i] = (fact[i-1] * i);

        while (!(fact[i] % 10)) {
            fact[i] /= 10;
        }

        fact[i] %= 10000000;
    }

    string n;
    while (cin >> n || !cin.eof()) {
        for (int i = 0; i < 5-n.length(); ++i)
            cout << ' ';
        
        cout << n << " -> " << fact[stoi(n)] % 10 << '\n';
    }
}