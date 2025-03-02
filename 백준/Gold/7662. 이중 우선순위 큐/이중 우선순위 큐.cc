#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct int_pq {
private:
    bool type; // 1 = max, 0 = min

public:
    int size{};
    int* list;

    int_pq(int s, bool t) { // init
        list = (int *)malloc(sizeof(int) * s + 1)
        , type = t;
    }

    void heapify(int);
    void push(int);
    int pop();
    int front();
    bool empty();
} pq;

void int_pq::heapify(int i) {
    int stand = i
        , left = 2*i
        , right = 2*i + 1;

    if (type) { // max
        if (left <= size && list[left] > list[stand])
            stand = left;
        if (right <= size && list[right] > list[stand])
            stand = right;
    }
    else { // min
        if (left <= size && list[left] < list[stand])
            stand = left;
        if (right <= size && list[right] < list[stand])
            stand = right;
    }
    
    if (stand != i) { // i가 가장 크거나 가장 작지 않은 경우 
        swap(list[stand], list[i]);
        heapify(stand);
    }
}
void int_pq::push(int n) {
    list[++size] = n;
    
    for (int i = size; i > 1; i /= 2) {
        if (!type && list[i/2] > list[i]) // max
            swap(list[i/2], list[i]);

        else if (type && list[i/2] < list[i]) // min
            swap(list[i/2], list[i]);
    }
}
int int_pq::pop() {
    int result = list[1];
    list[1] = list[size--]; // 맨 마지막 노드와 바꾸기

    heapify(1);

    return result;
}
int int_pq::front() {
    return list[1];
}
bool int_pq::empty() {
    return !size;
}

typedef struct double_pq {
private:
    int size{};
    unordered_map<int, int> cnt; // 큐 동기화
    pq max_pq, min_pq;

public:

    double_pq(int s) : max_pq(s, 1), min_pq(s, 0) {
    }

    void push(int);
    int pop(bool);
    int front(bool);
    bool empty();
} dpq;

void double_pq::push(int n) {
    ++size, ++cnt[n];
    max_pq.push(n);
    min_pq.push(n);
}
int double_pq::pop(bool type) {
    // 비었는지 검사 안함
    int top;
    --size;
    
    if (type)
        top = max_pq.pop()
        , --cnt[top];
    else if (!type)
        top = min_pq.pop()
        , --cnt[top];

    // 동기화
    while (!min_pq.empty() && !cnt[min_pq.front()])
        min_pq.pop();
    while (!max_pq.empty() && !cnt[max_pq.front()])
        max_pq.pop();
    
    return top;
}
int double_pq::front(bool type) {
    return type ? max_pq.front() : min_pq.front();
}
bool double_pq::empty() {
    return !size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        dpq dpq(n);

        while (n--) {
            char cmd;
            int param;

            cin >> cmd >> param;

            if (cmd == 'I')
                dpq.push(param);
            else if (!dpq.empty()) // D
                dpq.pop(param == 1 ? 1 : 0);
        }

        if (dpq.empty())
            cout << "EMPTY";
        else
            cout << dpq.front(1) << ' ' << dpq.front(0);
        cout << '\n';
    }
}