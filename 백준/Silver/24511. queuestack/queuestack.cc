#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int n;
    cin >> n;

    int real_size{};
    deque<int> array;
    deque<bool> types(n);
    for (int i = 0; i < n; ++i) {
        cin >> types[i];
        if (!types[i]) ++real_size;
    }
    
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (!types[i]) array.push_back(tmp);
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int o;
        cin >> o;

        array.push_front(o);
        cout << array.back() << ' ';
        array.pop_back();
    }
}