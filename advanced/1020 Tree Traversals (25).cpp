#include <bits/stdc++.h>

using namespace std;

struct node {
    using nodeptr = node *;
    
    node() = default;
    node(int v) : v(v), l(nullptr), r(nullptr) {}
    node(int v, nodeptr l, nodeptr r) : v(v), l(l), r(r) {}
    
    int v;
    nodeptr l, r;
};

node* build(const vector<int>& postorder, const vector<int>& inorder) {
    if (postorder.empty()) return nullptr;
    
    int v = postorder.back();
    node* root = new node(v);
    
    vector<int> l_postorder, l_inorder, r_postorder, r_inorder;
    
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == v) {
            l_inorder.assign(inorder.begin(), inorder.begin() + i);
            r_inorder.assign(inorder.begin() + i + 1, inorder.end());
            break;
        }
    }
    
    l_postorder.assign(postorder.begin(), postorder.begin() + l_inorder.size());
    r_postorder.assign(postorder.begin() + l_inorder.size(), prev(postorder.end()));
    
    root->l = build(l_postorder, l_inorder);
    root->r = build(r_postorder, r_inorder);
    
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> postorder(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    
    node* root = build(postorder, inorder);
    queue<node *>queue;
    queue.push(root);
    while (!queue.empty()) {
        auto d = queue.front();
        queue.pop();

        if (d == root) cout << d->v;
        else cout << ' ' << d->v;

        if (d->l) queue.push(d->l);
        if (d->r) queue.push(d->r);
    }
}
