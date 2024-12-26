#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string str;
    cin >> n >> m >> str;

    int cnt{}, IOI{};
    for (int i{}; i < m;) {
        if (str.substr(i, 3) == "IOI") {
            ++IOI, i += 2; // "IO"I
            if (IOI == n)
                ++cnt, --IOI;
        } else
            ++i, IOI = 0;
    }

    cout << cnt;
}