#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    while (1) {
        short n;
        cin >> n;

        if (cin.eof())
            return 0;
        
        deque<bool> visited(n, 0);
        vector<int> array(n);
        
        for (short i = 0; i < n; ++i) {
            cin >> array[i];
            if (i) {
                int diff = abs(array[i]-array[i-1]);
                if (diff >= 1 && diff < n)
                    visited[diff] = 1;
            }
        }

        bool flag{};
        for (short i = 1; i < n; ++i)
            if (!visited[i]) {
                flag = 1;
                cout << "Not jolly";
                break;
            }
        
        if (!flag)
            cout << "Jolly";
        cout << '\n';
    }
}