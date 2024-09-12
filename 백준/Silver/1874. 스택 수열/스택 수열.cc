#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

void solve(vector<int> &array, int index = 0, int top = 0) {
    static stack<int> _stack;
    static deque<bool> result;
    static int last_pop;
    if (top == array.size()+1) {
        result.pop_back();
        if (last_pop == array.back())
            for (auto &i : result)
                cout << (i ? '+' : '-') << '\n';
        else
            cout << "NO";
        return;
    }

    if (_stack.empty() || _stack.top() != array[index]) {
        _stack.push(top+1);
        result.push_back(1);
        solve(array, index, top+1);
    }
    else {
        result.push_back(0);
        last_pop = _stack.top();
        _stack.pop();
        solve(array, index+1, top);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> result(n);

    for (int i = 0; i < n; ++i)
        cin >> result[i];
    solve(result);
}