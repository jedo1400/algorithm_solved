#include <iostream>
#include <string>

using namespace std;

int main() {
    int result = 0;
    int count = 0, i = 666, buffer = 0;
    short n;

    cin >> n;
    while (1) {
        if (to_string(i).find("666") != string::npos) {
            count++;
            if (count == n) {
                result = i;
                break;
            }
        } i++;
    }
    cout << i;
}