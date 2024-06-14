#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, result;
    cin >> name;
    for (auto &i : name)
        if (i <= 90 && i != 45)
            result += i;
    cout << result;
}