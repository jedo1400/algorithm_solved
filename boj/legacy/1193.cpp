#include <iostream>
#include <string>

using namespace std;

string* getArray(int round) {
    string* array = new string[round-1];
    int left = 1, right = round-1;
    for (int i = 0; left <= round-1; ++i) {
        if ((round-1) % 2 != 0) array[i] += to_string(right) + "/" + to_string(left); 
        else array[i] += to_string(left) + "/" + to_string(right); 
        left++, right--;
    } return array;
}

int main() {
    int x, round, weight = 0;
    cin >> x;
    if (x <= 2) {
        cout << "1/" << x;
        return 0;
    }
    else
        for (int i = 1, j = 2; i < x; i += j, ++j)
            round = j+1;
    for (int i = 1; x > weight+i; ++i)
        weight = i*(i+1)/2;
    string* array = getArray(round);
    cout << array[x-weight-1];
}

/*
1. 1, 1
2. 2, 1
3. 1, 2
4. 3, 1
5. 2, 2
6, 3, 1
7. 4, 1
*/