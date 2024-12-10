#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;

    while (cin >> a >> b) {
        int cur{};

        for (auto &i : b)
            if (i == a[cur])
                ++cur;

        cout << (cur == a.size() ? "Yes" : "No") << '\n';
    }
}