#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short cnt{};
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (b.length() > a.length()) {
        cout << 0;
        return 0;
    }
    
    for (short i = 0; i <= a.length()-b.length(); ++i) {
        bool flag{};
        for (short j = 0; j < b.length(); ++j) {
            if (a[i+j] != b[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            ++cnt, i += b.length()-1;
    }

    cout << cnt;
}