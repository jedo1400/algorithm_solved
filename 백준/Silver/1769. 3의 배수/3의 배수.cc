#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;

    short cnt{};
    while (n.length() != 1) {
        int tmp{};
        for (auto &i : n)
            tmp += i-48;
        n = to_string(tmp), ++cnt;
    }

    int rst;
    cout << cnt << '\n' << ((rst = stoi(n)) % 3 && rst ? "NO" : "YES");
}