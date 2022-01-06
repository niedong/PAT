#include <bits/stdc++.h>

using namespace std;

struct node {
    using nodeptr = node*;

    node() = default;
    node(int value) : value(value), lhs(nullptr), rhs(nullptr) {}
    node(int value, nodeptr lhs, nodeptr rhs) : value(value), lhs(lhs), rhs(rhs) {}

    int value;
    nodeptr lhs, rhs;
};

void dfs(node* root, vector<vector<int>>& res, vector<int>& v) {
    if (root == nullptr) return;
    
    v.emplace_back(root->value);

    if (root->lhs == nullptr && root->rhs == nullptr) {
        res.emplace_back(v);
        v.pop_back();
        return;
    }

    if (root->rhs) dfs(root->rhs, res, v);
    if (root->lhs) dfs(root->lhs, res, v);
    v.pop_back();
}

int main() {
    int n, s = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    queue<node*> queue;
    node* root = new node(v[s++]);
    queue.push(root);
    while (!queue.empty()) {
        node* t = queue.front();
        queue.pop();
        if (s < v.size()) {
            t->lhs = new node(v[s++]);
            queue.push(t->lhs);
        }
        if (s < v.size()) {
            t->rhs = new node(v[s++]);
            queue.push(t->rhs);
        }
    }

    vector<vector<int>> res;
    vector<int> t;
    dfs(root, res, t);

    bool isheap = true, ismin = false, ismax = false;
    for (auto const& v: res) {
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0) {
                cout << v[i];
                continue;
            }
            cout << ' ' << v[i];
            if (v[i] > v[i - 1]) ismin = true;
            if (v[i] < v[i - 1]) ismax = true;
        }
        cout << endl;
        isheap = ismax ^ ismin;
    }
    if (isheap) {
        if (ismax) cout << "Max Heap" << endl;
        if (ismin) cout << "Min Heap" << endl;
    }
    else cout << "Not Heap" << endl;
}
