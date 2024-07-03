#include <iostream>
#include <vector>

using namespace std;

short getSizeOfBiggestFoursquare(vector<vector<char>> &array) {
    short min = (array.size() > array[0].size() ? array[0].size() : array.size())
        , biggest = 1; // 50*50 = 2500 < SHRT_MAX

    for (short i = 1; i <= min; ++i)
        for (short y = 0; y < array.size()-i; ++y)
            for (short x = 0; x < array[0].size()-i; ++x) {
                bool isFoursquare = true;
                if (array[y+i][x] != array[y][x])   isFoursquare = false;
                if (array[y][x+i] != array[y][x])   isFoursquare = false;
                if (array[y+i][x+i] != array[y][x]) isFoursquare = false;
                
                if (isFoursquare)
                    biggest = (i+1)*(i+1);
            }
    
    return biggest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m;
    cin >> n >> m;
    vector<vector<char>> array(n, vector<char>(m));

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j)
            cin >> array[i][j];
    
    cout << getSizeOfBiggestFoursquare(array);
}