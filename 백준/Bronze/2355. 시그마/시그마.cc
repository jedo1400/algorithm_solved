#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a > b) {
        int swap = a;
        a = b
        , b = swap;
    }

    cout << (((long long)a+b) * ((long long)b-a+1)) / 2;
}