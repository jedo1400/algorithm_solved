#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        cout << (str.length() >= 6 && str.length() <= 9 ? "yes" : "no") << '\n';
    }
}