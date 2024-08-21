#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (1) {
        unordered_map<int, bool> array;
        int n, m, o, rst{};
        cin >> n >> m;

        if (!n && !m)
            break;
        
        for (int i = 0; i < n; ++i) { // 상근
            cin >> o;
            array[o] = 1;
        }

        for (int i = 0; i < m; ++i) { // 선영
            cin >> o;
            if (array[o])
                ++rst;
        }
    
        cout << rst << '\n';
    }
}