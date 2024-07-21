#include <iostream>

using namespace std;

class deque {
public:
    int* array;
    int size; // 배열 길이
    int actual_size{}; // 덱의 실제 길이

    deque(const int& n) {
        array = new int[n];
        size = n;
        __front = n-1;
    }

    ~deque() {
        delete [] array;
    }

    int operator[](int i) {
        return array[i];
    }

    bool empty();
    void push_front(const int&);
    void push_back(const int&);
    int pop_front();
    int pop_back();
    int front();
    int back();

    int begin();
    int end();

private:
    int __front, __back{};
    int getNextIndex(const int&);
    int getPrevIndex(const int&);
};

int deque::getNextIndex(const int& index) {
    if (index+1 >= size)
        return index - (size - 1);
    return index+1;
}

int deque::getPrevIndex(const int& index) {
    if (!index)
        return size-1;
    return index-1;
}

bool deque::empty() {
    return !actual_size;
}

void deque::push_front(const int &n) {
    array[__front] = n
    , __front = getPrevIndex(__front);

    ++actual_size;
}

void deque::push_back(const int &n) {
    array[__back] = n
    , __back = getNextIndex(__back);

    ++actual_size;
}

int deque::pop_front() {
    if (empty())
        return -1;

    __front = getNextIndex(__front)
    , --actual_size;

    return array[__front];
}

int deque::pop_back() {
    if (empty())
        return -1;

    __back = getPrevIndex(__back)
    , --actual_size;

    return array[__back];
}

int deque::front() {
    if (empty())
        return -1;
    return array[getNextIndex(__front)];
}

int deque::back() {
    if (empty())
        return -1;
    return array[getPrevIndex(__back)];
}

int deque::begin() {
    return getNextIndex(__front);
}

int deque::end() {
    return getPrevIndex(__back);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    deque deque(n);

    string cmd;
    for (int i = 0; i < n; ++i) {
        getline(cin, cmd);
        
        switch (cmd[0]) {
            case '1': deque.push_front(stoi(cmd.substr(2))); 
                break;
            case '2': deque.push_back(stoi(cmd.substr(2))); 
                break;
            case '3': cout << deque.pop_front() << '\n';
                break;
            case '4': cout << deque.pop_back() << '\n';
                break;
            case '5': cout << deque.actual_size << '\n';
                break; 
            case '6': cout << deque.empty() << '\n';
                break;
            case '7': cout << deque.front() << '\n';
                break;
            case '8': cout << deque.back() << '\n';
        }
    }
}