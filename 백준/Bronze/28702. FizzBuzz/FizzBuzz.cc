#include <iostream>

using namespace std;

int main() {
    string a;
    int result;

    for (short i = 3; i >= 1; --i) {
        cin >> a;

        try {
            result = stoi(a) + i;
        }
        catch (const exception& e) {
            continue;
        }
    }

    bool multi_3 = result % 3 ? 0 : 1,
        multi_5 = result % 5 ? 0 : 1;

    if (multi_3) cout << "Fizz";
    if (multi_5) cout << "Buzz";
    if (!multi_3 && !multi_5) cout << result;
}