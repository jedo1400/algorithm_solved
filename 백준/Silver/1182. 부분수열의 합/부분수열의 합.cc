#include <iostream>
#include <vector>

using namespace std;

int getProperSumCases(const vector<int> &array, const int &n, const int& s, int depth = 0, int sum = 0) {
    static int result{};
    if (n == depth) {
        if (s == sum) 
            ++result;
        return 1;
    }

    getProperSumCases(array, n, s, depth+1, sum);
    getProperSumCases(array, n, s, depth+1, sum+array[depth]);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    int s;
    cin >> n >> s;
    vector<int> array(n);

    for (short i = 0; i < n; ++i)
        cin >> array[i];

    cout << getProperSumCases(array, n, s) - (!s ? 1 : 0); // 부분 수열의 원소 개수는 양수여야함
}