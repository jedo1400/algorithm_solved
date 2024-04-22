#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, result = 0;
    for (short i = 0; i < 5; ++i) {
        cin >> n;
        result += n*n;
    } cout << result%10;
}