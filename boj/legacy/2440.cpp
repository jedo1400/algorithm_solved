#include <iostream>
#include <vector>

using namespace std;

bool isValid(bool array[][50], short n, short m) {
    if (!array[n][m])
        return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    short n;
    cin >> n;

    for (short i = 0; i < n; ++i) {
        for (short j = n-i; j > 0; --j)
            cout << '*';
        cout << endl;
    }
}
