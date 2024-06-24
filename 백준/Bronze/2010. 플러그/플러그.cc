#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    short plugs, rst = 1;
    for (int i = 0; i < n; ++i) {
        cin >> plugs;
        rst += plugs-1;
    }

    cout << rst;
}