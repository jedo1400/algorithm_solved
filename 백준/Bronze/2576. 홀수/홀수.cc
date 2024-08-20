#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short sum{}, smallest = 100;

    for (short i{}; i < 7; ++i) {
        short num;
        cin >> num;
        if (num % 2) {
            sum += num;
            if (smallest > num) smallest = num;
        }
    } 

    if (!sum)
        cout << -1;
    else 
        cout << sum << '\n' << smallest;
}