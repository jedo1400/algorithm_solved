#include <iostream>

using namespace std;

class queue {
public:
    int* array;
    short size; // 배열 길이
    short actual_size{}; // 큐의 실제 길이

    queue(const int& n) {
        array = new int[n];
        size = n;
    }

    ~queue() {
        delete [] array;
    }

    int operator[](short i) {
        return array[i];
    }

    bool empty();
    void push(const int&);
    int pop();
    int front();
    int back();

    // int begin();
    // int end();

private:
    short __front{}, __back{};
    void getNextIndex(short&);
};

void queue::getNextIndex(short& index) {
    if (index >= size)
        index -= size;
    else
        ++index;
}

bool queue::empty() {
    return __front == __back;
}

void queue::push(const int &n) {
    array[__back] = n;
    getNextIndex(__back);
    ++actual_size;
}

int queue::pop() {
    if (empty())
        return -1;
    short prev_index = __front;
    getNextIndex(__front);
    --actual_size;
    return array[prev_index];
}

int queue::front() {
    if (empty())
        return -1;
    return array[__front];
}

int queue::back() {
    if (empty())
        return -1;
    return array[__back == 0 ? size-1 : __back-1];
}

// int queue::begin() {
//     return __front;
// }

// int queue::end() {
//     return __back;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    cin.ignore();
    queue queue(n);

    string cmd;
    for (short i = 0; i < n; ++i) {
        getline(cin, cmd);
        
        switch (cmd[0]) {
            case 'p':
                if (cmd[1] == 'u') queue.push(stoi(cmd.substr(4))); // push 
                if (cmd[1] == 'o') cout << queue.pop() << '\n'; // pop
                break;
            case 's': cout << queue.actual_size << '\n'; // size
                break;
            case 'e': cout << queue.empty() << '\n';
                break;
            case 'f': cout << queue.front() << '\n';
                break;
            case 'b': cout << queue.back() << '\n';
        }

        // for (short i = queue.begin(); i != queue.end(); queue.getNextIndex(i))
        //     cout << queue[i];
        // cout << '\n';
    }
}