#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    vector<int> param;
    cin >> a >> b;
    short temp = b;
    for (short i = 100; i >= 1; i /= 10) {
        param.push_back(a*(temp/i));
        temp %= i;
    } for (short i = 2; i >= 0; --i) cout << param[i] << endl;
    cout << a*b;
}