#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum{}, max{}, r{};
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m;
            sum += m;
            
            if (max < m)
                max = m, r = i;
            else if (max == m)
                r = 0;
        }

        if (r)
            cout << (sum/2 < max ? "majority winner " : "minority winner ") << r;
        else
            cout << "no winner";
        cout << '\n';
    }
}