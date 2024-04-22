#include <iostream>
#include <string>

using namespace std;

int main() {
    int array[26] = {0,};
    int largestIndex = -1, largestNum = -1;
    bool isDuplicated = 0;
    short ascii;
    string input;

    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        if ((ascii = (int)input[i]) > 64 && ascii < 91)
            array[ascii-65]++;
        else if (ascii > 96 && ascii < 123)
            array[ascii-97]++;
    }

    for (int i = 0; i < 26; ++i)
        if (largestIndex == -1 || array[i] > largestNum)
            largestIndex = i, largestNum = array[i], isDuplicated = 0;
        else if (array[i] == largestNum)
            isDuplicated = 1;
    
    if (isDuplicated) cout << '?';
    else if (largestIndex > 25) cout << (char)(largestIndex+97);
    else cout << (char)(largestIndex+65);

    return 0;
}