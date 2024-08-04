#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    while (n--) {
        string a, b;
        cin >> a >> b;

        cout << "Distances: ";
        for (short i = 0; i < a.length(); ++i)
            cout << (b[i] >= a[i] ? b[i]-a[i] : b[i]+26 - a[i]) << ' ';
        cout << '\n';
    }
}