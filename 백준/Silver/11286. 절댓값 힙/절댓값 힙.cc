#include <iostream>

using namespace std;

struct abs_heap {
private:
    void swap(int&, int&);

public:
    int *arr, size{};
    abs_heap(int size) {
        arr = new int[size];
    }

    bool empty();
    int abs(int);
    void push(int);
    int pop();
} typedef heap;

bool abs_heap::empty() {
    return !size;
}

int abs_heap::abs(int n) {
    return n < 0 ? -n : n;
}

void abs_heap::swap(int &a, int &b) {
    int tmp = a;
    a = b, b = tmp;
}

void abs_heap::push(int n) {
    arr[size] = n;

    if (!empty()) {
        int parent = size/2, cur = size;

        while (cur) {
            int ap = abs(arr[parent]), ac = abs(arr[cur]);
            if ((ap > ac) || (ac == ap && arr[parent] > arr[cur]))
                swap(arr[parent], arr[cur]);
            cur = parent, parent /= 2;
        }
    }

    ++size;
}

int abs_heap::pop() {
    if (empty())
        return 0;

    int result = arr[0];
    arr[0] = arr[--size]; // 배열의 마지막 요소를 맨 위로 이동
    
    int parent = 0, child = 1; // 좌측 자식
    while (child <= size) {
        int ap = abs(arr[parent]);
        if (child < size) {
            if (abs(arr[child+1]) < abs(arr[child])) ++child; // 우측 자식이 좌측 자식보다 작은 경우
            else if (abs(arr[child+1]) == abs(arr[child]) && arr[child+1] < arr[child]) ++child;
        }
        int ac = abs(arr[child]);
        if (ap > ac || (ac == ap && arr[parent] > arr[child])) swap(arr[parent], arr[child]);
        parent = child, child *= 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    heap heap(n);

    while (n--) {
        int m;
        cin >> m;
        
        if (!m) cout << heap.pop() << '\n';
        else heap.push(m);
    }
}