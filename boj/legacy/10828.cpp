#include <iostream>
#include <string>

using namespace std;

int pos = 0, stack[10000] = {0,};

void top() {
    cout << (pos ? stack[pos] : -1);
}

void empty() {
    cout << (pos ? 0 : 1);
}

void size() {
    cout << pos;
}

void push(int i) {
    ++pos, stack[pos] = i;
}

void pop() {
    cout << (pos ? stack[pos] : -1);
    stack[pos] = 0, pos -= pos ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string cmd, memo;
    int n;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, cmd);
        memo = cmd.substr(0, 2);
        if (memo == "pu") {
            push(stoi(cmd.substr(4)));
            continue;
        }
        else if (memo == "po")
            pop();
        else if (memo == "si")
            size();
        else if (memo == "em")
            empty();
        else
            top();
        cout << '\n';
    }
}