#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    short n[3];
    short flagSame, biggest, smallSum;
    
    while (1) {
        flagSame = 2, biggest = SHRT_MIN, smallSum = 0;
        for (short i = 0; i < 3; ++i) {
            cin >> n[i];
            if (i > 0 && n[i-1] != n[i] && (i == 2 ? n[0] != n[2] : 1)) flagSame--;
            if (biggest < n[i]) biggest = n[i];
            smallSum += n[i];
        } if (!n[0] && flagSame == 2) return 0;
        if (biggest >= smallSum - biggest) cout << "Invalid";
        else if (flagSame == 2) cout << "Equilateral";
        else if (flagSame == 1) cout << "Isosceles";
        else if (flagSame == 0) cout << "Scalene";
        cout << endl;
    } return 0;
}