#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string tmp;
    cin >> n;
    cin.ignore();

    for (short i = 1; i <= n; ++i) {
        getline(cin, tmp);
        cout << i << ". " << tmp << '\n';
    }

}