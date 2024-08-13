#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;

        for (auto &i : input)
            cout << (char)(i < 97 ? i + 32 : i);
        cout << '\n';
    }
}