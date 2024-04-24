#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string ps;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        int opened = 0;
        getline(cin, ps);
        for (int i = 0; i < ps.length() && opened >= 0; ++i)
            if (ps[i] == '(') ++opened;
            else --opened;
        cout << (!opened ? "YES" : "NO") << '\n';
    }

}