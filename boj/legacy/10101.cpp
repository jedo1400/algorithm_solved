#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    short n[3], m = 0;
    for (short i = 0; i < 3; ++i) { cin >> n[i]; m += n[i]; }
    
    if (m != 180)
        cout << "Error";
    else if (n[0] == 60 && n[0] == n[1] && n[1] == n[2])
        cout << "Equilateral";
    else
        if (n[0] == n[1] || n[1] == n[2] || n[2] == n[0])
            cout << "Isosceles";
        else if (n[0] != n[1] && n[1] != n[2] && n[2] != n[0])
            cout << "Scalene";
}