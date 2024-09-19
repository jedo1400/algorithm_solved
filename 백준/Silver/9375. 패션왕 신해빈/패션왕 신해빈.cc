#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    short t;
    cin >> t;

    while (t--) {
        short n;
        cin >> n;
        map<string, short> wear;
        for (short i = 0; i < n; ++i) {
            string type;
            cin >> type >> type;
            ++wear[type];
        }

        int result = 1;
        for (auto &i : wear) {
            result *= (i.second + 1); // i.first 종류의 입을 것을 아예 입지 않는 경우 +1
        }

        cout << result-1 << '\n'; // 아무것도 입지 않는 경우 -1
    }
}
