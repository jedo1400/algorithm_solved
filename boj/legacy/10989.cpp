#include <iostream>

int num_array[10001] = {0,};

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, buff, printed = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        num_array[buff]++;
    }
    for (int i = 1; i <= 10000; ++i)
        if (num_array[i]) {
            for (int j = 0; j < num_array[i]; ++j)
                cout << i << "\n";
        }
}