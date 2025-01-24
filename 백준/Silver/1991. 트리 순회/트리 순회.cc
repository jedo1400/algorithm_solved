#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void preorder(vector<pair<int, int>> &tree, int cur = 0) {
    if (cur < 0)
        return;

    cout << (char)(cur + 'A');
    preorder(tree, tree[cur].first);
    preorder(tree, tree[cur].second);
}

void inorder(vector<pair<int, int>> &tree, int cur = 0) {
    if (cur < 0)
        return;

    inorder(tree, tree[cur].first);
    cout << (char)(cur + 'A');
    inorder(tree, tree[cur].second);
}

void postorder(vector<pair<int, int>> &tree, int cur = 0) {
    if (cur < 0)
        return;

    postorder(tree, tree[cur].first);
    postorder(tree, tree[cur].second);
    cout << (char)(cur + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> tree(n);

    while (n--) {
        char p, l, r;
        cin >> p >> l >> r;
        tree[p-'A'] = { l-'A', r-'A' }; // . =  -19
    }

    preorder(tree); cout << '\n';
    inorder(tree); cout << '\n';
    postorder(tree);
}