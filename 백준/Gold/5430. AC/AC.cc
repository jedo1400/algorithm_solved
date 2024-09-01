#include <iostream>
#include <string>
#include <deque>

using namespace std;

void split(deque<short>& array, const string& str_array) {
    int num{};
    
    for (auto &i : str_array) {
        if ((i == ',' || i == ']') && num) { // 덱의 정의역은 100 이하의 자연수
            array.push_back(num);
            num = 0;
        }
        else if (i >= 48 & i <= 57) {
            if (num) num *= 10;
            num += i-48;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short t;
    cin >> t;

    while (t--) {
        string cmd, prim;
        int n;
        bool comp{}, pos{}; // 0 = front, 1 = back
        deque<short> array;

        cin >> cmd >> n >> prim;

        split(array, prim);

        for (auto &i : cmd)
            if (i == 'R')
                pos = pos ? 0 : 1;
            else {
                if (array.empty()) {
                    cout << "error";
                    comp = 1;
                    break;
                }
                pos ? array.pop_back() : array.pop_front();
            }
        
        if (!comp) {
            cout << '[';
            if (!pos)
                for (int i = 0; i < array.size(); ++i) {
                    cout << array[i];
                    if (array.size()-1 != i) cout << ',';
                }
            else
                for (int i = array.size()-1;  i >= 0; --i) {
                    cout << array[i];
                    if (i) cout << ',';
                }
            cout << ']';
        }
        cout << '\n';
    }
}