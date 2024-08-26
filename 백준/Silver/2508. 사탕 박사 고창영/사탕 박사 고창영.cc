#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short t;
    cin >> t;

    while (t--) {
        short r, c, rst{};
        cin >> r >> c;

        vector<string> array(r);

        for (short i = 0; i < r; ++i)
            cin >> array[i];
        
        for (short i = 0; i < r; ++i)
            for (short j = 0; j < c; ++j)
                if (array[i][j] == 'o') {
                    if ((i && i < r-1) && (array[i-1][j] == 'v' && array[i+1][j] == '^'))
                        ++rst;
                    if ((j && j < c-1) && (array[i][j-1] == '>' && array[i][j+1] == '<'))
                        ++rst;
                }

        cout << rst << '\n';
    }
}