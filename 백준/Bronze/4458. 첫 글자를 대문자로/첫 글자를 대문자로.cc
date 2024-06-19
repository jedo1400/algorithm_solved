#include <iostream>
#include <string>
#define u_int unsigned int

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    u_int n;
    string s;
    cin >> n;
    cin.ignore();

    for (u_int i = 0; i < n; ++i) {
        getline(cin, s);
        if (s[0] >= 97)
        s[0] = s[0]-32;
        cout << s << '\n';
    }
}