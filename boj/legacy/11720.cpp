#include <iostream>
#include <string>

using namespace std;

int main() {
    short n;
    int result = 0;
    cin >> n;

    string numbers;
    cin >> numbers;

    for (short i = 0; i < n; ++i)
        result += (int)numbers[i]-48;
    cout << result;
}