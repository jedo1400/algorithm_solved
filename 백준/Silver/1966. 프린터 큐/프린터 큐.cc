#include <iostream>
#include <utility>
#include <deque>

using namespace std;

short printQueue(deque< pair<short, short> > &array, const short &target, short count = 1) {
    const short front_priority = array.front().first;

    for (auto &i : array)
        if (front_priority < i.first) {
            array.push_back(array.front());
            array.pop_front();
            return printQueue(array, target, count);
        }
    
    if (array[0].second == target)
        return count;
    else {
        ++count;
        array.pop_front();
    }

    return printQueue(array, target, count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int i{}; i < tc; ++i) {
        short n, m;
        cin >> n >> m;
        deque< pair<short, short> > array(n);

        for (int j{}; j < n; ++j) {
            short tmp;
            cin >> tmp;
            array[j] = make_pair(tmp, j);
        }

        cout << printQueue(array, m) << '\n';
        
        array.clear();
    }
}