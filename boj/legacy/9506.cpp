#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    string text;

    while (1) {
        cin >> n;
        if (n == -1)
            return 0;
        text = to_string(n) + " = ", m = 0;
        for (int i = 1; i < n; ++i)
            if (n % i == 0) {
                text.append(to_string(i));
                if (i*2 != n) text.append(" + ");
                m += i;
            }
        if (n == m) cout << text;
        else cout << n << " is NOT perfect.";
        cout << endl;
    }
}