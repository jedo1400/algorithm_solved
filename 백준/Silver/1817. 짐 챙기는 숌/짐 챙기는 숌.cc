#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (!n) {
        cout << 0;
        return 0;
    }

    int box = 1, stack{};
    for (int i{}; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (stack+tmp <= m)
            stack += tmp;
        else
            ++box, stack = tmp;
    }

    cout << box;
}