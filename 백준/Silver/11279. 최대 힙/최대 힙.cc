#include <iostream>

using namespace std;

struct max_heap {
private:
    void swap(int&, int&);

public:
    int *array, size{};
    max_heap(int size) {
        array = new int[size];
    }

    bool empty();
    void push(int);
    int pop();
} typedef heap;

bool max_heap::empty() {
    return !size;
}

void max_heap::swap(int &a, int &b) {
	int tmp = a;
	a = b, b = tmp;
}

void max_heap::push(int n) {
    array[size] = n;

    if (!empty()) {
        int parent = size/2, cur_pos = size;
        
        while (parent >= 0 && array[parent] < array[cur_pos]) {
            swap(array[parent], array[cur_pos]);
            cur_pos = parent, parent /= 2;
        }
    }
    ++size;
}

int max_heap::pop() {
	if (empty())
		return 0;

	int result = array[0];
	array[0] = array[--size]; // 힙 사이즈 줄이기

	int child = 1, parent = 0;
	while (child <= size) {
		if (child+1 <= size && array[child+1] > array[child]) ++child;
		if (array[child] < array[parent]) break;
		swap(array[child], array[parent]); // 부모자식바꾸기
		parent = child, child *= 2; // 자식바꾸기
	}

	return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
	cin >> n;
	heap heap(n);

	while (n--) {
		int n;
		cin >> n;
		if (!n) cout << heap.pop() << '\n';
		else heap.push(n);
	}
}