#include <iostream>
#include <vector>

using namespace std;

void post_order(vector<int> &tree, int s, int e) {
	if (s >= e) return; // 종료조건
	int lr = -1; // 부모 노드의 키보다 큰 값을 가지고 있는 노드의 인덱스

	for (int i = s+1; i < e; ++i)
		if (tree[s] < tree[i]) {
			lr = i;
			break;
		}
	
	if (lr != -1) { // 우측 서브트리가 있다면
		post_order(tree, s+1, lr); // 좌
		post_order(tree, lr, e); // 우
	} else // 없다면
		post_order(tree, s+1, e); 

	cout << tree[s] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	vector<int> tree;
	
	int n;
	while (cin >> n)
		tree.push_back(n);

	post_order(tree, 0, tree.size());
}