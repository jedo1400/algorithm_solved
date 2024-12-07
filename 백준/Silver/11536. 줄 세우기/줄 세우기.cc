#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    bool desc = 1, asc = 1;
    string before;
    cin >> before;

    while (--n) {
        string str;
        cin >> str;

        if (str < before) asc = 0;
        else desc = 0;
        before = str;
    }

    if (asc) cout << "INCREASING";
    else if (desc) cout << "DECREASING";
    else cout << "NEITHER";
}