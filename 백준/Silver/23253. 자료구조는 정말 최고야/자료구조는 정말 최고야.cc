#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    bool result = 1;
    cin >> n >> m;
    
    while (m--) {
        int o;
        cin >> o;
        for (int i{}; i < o; ++i) {
            static int p, before;
            cin >> p;

            if (i && before < p)
                result = 0;

            before = p;
        }
    }

    cout << (result ? "Yes" : "No");
}