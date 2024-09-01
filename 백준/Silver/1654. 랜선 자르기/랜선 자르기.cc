#include <algorithm>
#include <iostream>
#include <vector>
#define uint unsigned int

using namespace std;

uint getLongestCableLen(const vector<uint> &array, uint start, uint end, uint value) {
    uint mid = (start+end) / 2;

    uint result{};
    for (auto &i : array)
        result += i/mid;

    if (start > end)
        return mid;
    if (result >= value)
        return getLongestCableLen(array, mid+1, end, value);
    if (result < value)
        return getLongestCableLen(array, start, mid-1, value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short k; // 선의 갯수
    uint n; // 필요한 선의 갯수
    cin >> k >> n;

    vector<uint> array(k);
    for (short i = 0; i < k; ++i)
        cin >> array[i];

    sort(array.begin(), array.end());

    cout << getLongestCableLen(array, 1, array.back(), n);
}