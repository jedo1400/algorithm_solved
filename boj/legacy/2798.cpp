#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    short n;
    bool flagBreak = 0;
    int m, temp, biggest = 0;
    cin >> n >> m;
    int* arr = new int[n];

    for (short i = 0; i < n; ++i)
        cin >> arr[i];
    
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < n; ++j) {
            if (j != i)
                for (short k = 0; k < n; ++k) {
                    if (k != j && k != i && (temp = arr[i]+arr[j]+arr[k]) > biggest && temp <= m)
                        biggest = temp;
                    if (temp == m) {
                        flagBreak = 1;
                        break;
                    }
                } if (flagBreak)  break;
        } if (flagBreak)  break;
    }
    cout << biggest;
}


