#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;
        vector<int> array(m);

        for (auto &i : array)
            cin >> i;
        
        for (int i = 1; i < 100000; ++i) {
            deque<bool> used(100000, 0);

            bool comp = 1;
            for (auto &j : array) {
                if (used[j % i]) {
                    comp = 0;
                    break;
                }
                used[j % i] = 1;
            }
            if (comp) {
                cout << i << '\n';
                break;
            }
        }
    }
}