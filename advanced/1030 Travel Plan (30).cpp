#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node() = default;
    Node(int id, int dist) : id(id), dist(dist) {}
    bool operator<(const Node& node) const {
        return dist > node.dist;
    }

    int id, dist;
};

int main() {
    constexpr int inf = numeric_limits<int>::max() / 2;
    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    vector<vector<int>> dist(n, vector<int>(n, inf)), cost(n, vector<int>(n, inf));
    while (m--) {
        int s, e, d, c;
        cin >> s >> e >> d >> c;
        dist[s][e] = dist[e][s] = d;
        cost[s][e] = cost[e][s] = c;
    }
    for (int i = 0; i < n; ++i) dist[i][i] = cost[i][i] = 0;

    priority_queue<Node> queue;
    vector<int> d(n, inf), visited(n), c(n, inf), w(n);
    d[src] = 0;
    c[src] = 0;
    queue.emplace(src, 0);
    while (!queue.empty()) {
        auto node = queue.top();
        queue.pop();

        visited[node.id] = 1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (node.dist + dist[node.id][i] < d[i]) {
                    d[i] = node.dist + dist[node.id][i];
                    c[i] = c[node.id] + cost[node.id][i];
                    w[i] = node.id;
                    queue.emplace(i, d[i]);
                }
                else if (node.dist + dist[node.id][i] == d[i]) {
                    if (c[i] > c[node.id] + cost[node.id][i]) {
                        c[i] = c[node.id] + cost[node.id][i];
                        w[i] = node.id;
                    }
                }
            }
        }
    }

    stack<int> stack;
    stack.push(dst);
    while (w[stack.top()] != src) stack.push(w[stack.top()]);
    cout << src;
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
    cout << ' ' << d[dst] << ' ' << c[dst] << endl;
}
