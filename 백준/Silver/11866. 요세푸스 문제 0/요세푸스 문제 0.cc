#include <iostream>
#include <vector>

using namespace std;

int idx = 0, frt = 0;

int empty() {
    return idx-frt ? 0 : 1;
}

void enqueue(int* queue, int n) {
    queue[idx++] = n;
}

int dequeue(int* queue) {
    return empty() ? -1 : queue[frt++];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int* queue = new int[n*n];
    vector<int> result;

    for (int i = 0; i < n; ++i)
        enqueue(queue, i+1);

    while (result.size() < n-1) {
        for (int i = 0; i < k-1; ++i)
            enqueue(queue, dequeue(queue));
        result.push_back(dequeue(queue));
    }

    cout << '<';
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << ", ";

    for (int i = frt; i < idx; ++i)
        cout << queue[i] << (i+1 < idx ? ", " : ">");
    
    delete[] queue;
}