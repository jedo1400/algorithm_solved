#include <iostream>
#include <string>

using namespace std;

int main() {
    short n;
    string input;
    cin >> n;

    for (short i = 0; i < n; ++i) {
        cin >> input;
        cout << "Do-" << (input[input.length()/2-1] ^ input[input.length()/2] ? "it-Not" : "it") << '\n';
    }
}