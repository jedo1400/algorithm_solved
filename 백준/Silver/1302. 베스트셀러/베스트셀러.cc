#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    short n;
    cin >> n;
    map<string, short> list;

    while (n--) {
        string m;
        cin >> m;
        ++list[m];
    }

    short largest{};
    string result;
    for (auto &i : list)
        if (i.second > largest)
            result = i.first, largest = i.second;

    cout << result;
}