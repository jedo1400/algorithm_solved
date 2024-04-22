#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    cin >> n >> m;
    map<int, bool> A, B, A_replica; // A_rep = A, A = A-B, B = B-A
    for (short i = 0; i < 2; ++i) {
        for (int j = 0; j < (!i ? n : m); ++j) {
            cin >> temp;
            if (!i)
                A[temp] = 1;
            else {
                A.erase(temp);
                B[temp] = 1;
            }
        }
        if (!i) A_replica.insert(A.begin(), A.end());
    } // A-B
    
    for (auto iter = A_replica.begin(); iter != A_replica.end(); ++iter)
        B.erase(iter->first);
    // B-A
    
    cout << A.size() + B.size();
}