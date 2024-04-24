#include <iostream>
#include <vector>

using namespace std;

int idx = 0;

void push(int* stack, int n) {
    stack[idx++] = n;
}

int pop(int* stack) {
    return !idx ? -1 : stack[--idx];
}

bool empty() {
    return !idx ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int* stack = new int[n];
    cin.ignore();
    string cmd;

    for (int i = 0; i < n; ++i) {
        getline(cin, cmd);
        switch((int)cmd[0]-48) {
            case 1: // push
                push(stack, stoi(cmd.substr(2)));
                break;
            case 2: // pop
                cout << pop(stack) << '\n';
                break;
            case 3: // count
                cout << idx << '\n';
                break;
            case 4: // empty
                cout << empty() << '\n';
                break;
            case 5: // top
                cout << (empty() ? -1 : stack[idx-1]) << '\n';
        }
    }
    delete[] stack;
}