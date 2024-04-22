#include <iostream>
#include <cmath>

using namespace std;

short numlen(int);
short* splitNumber(int, short);
int sortArraytoNumber(short*, short);

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    short length = numlen(n)+1;
    short* arr_pointer = splitNumber(n, length);
    cout << sortArraytoNumber(arr_pointer, length);
    delete [] arr_pointer;
}

short numlen(int input) {
    short length = 0;
    for (int i = 1; input > 10; i *= 10)
        input /= 10, length++;
    return length;
}

short* splitNumber(int input, short size) {
    short length = numlen(input);
    int temp;
    short* array = new short[length+1];

    for (short i = length; i >= 0; --i)
        array[i] = input/(int)pow(10, i), input %= (int)pow(10, i);
    return array;
}

int sortArraytoNumber(short* array, short size) {
    int result = 0;
    short temp;

    for (short i = 0; i < size; ++i)
        for (short j = 1; j < size; ++j)
            if (i != j && array[j] < array[j-1])
                temp = array[j]
                , array[j] = array[j-1]
                , array[j-1] = temp;

    for (short i = 0; i < size; ++i)
        result += array[i]*(int)pow(10, i);
    return result;
}