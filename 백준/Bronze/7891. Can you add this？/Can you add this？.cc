#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
}