#include <iostream>
#include <vector>

bool num_array[2000000] = {0,};

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, buff, printed = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        num_array[1000000+buff] = 1;
    }

    for (int i = 0; printed < n; ++i)
        if (num_array[i]) {
            cout << i-1000000 << "\n";
            printed++;
        }
}