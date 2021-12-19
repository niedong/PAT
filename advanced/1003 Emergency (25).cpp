#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node(int id, int dist) : id(id), dist(dist) {}

    bool operator<(const Node& node) const {
        return dist > node.dist;
    }

    int id, dist;
};

int main() {
    constexpr int inf = numeric_limits<int>::max() / 2;
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;

    vector<vector<int>> map(N, vector<int>(N, inf));
    vector<int> man(N), c(N), w(N);

    for (int i = 0; i < N; ++i) cin >> man[i];

    for (int i = 0; i < M; ++i) {
        int s, e, l;
        cin >> s >> e >> l;
        map[s][e] = l;
        map[e][s] = l;
    }

    for (int i = 0; i < N; ++i) map[i][i] = 0;

    vector<int> d(N, inf), visited(N);
    d[C1] = 0;
    c[C1] = 1;
    w[C1] = man[C1];

    priority_queue<Node> queue;
    queue.emplace(C1, 0);
    while (!queue.empty()) {
        auto node = queue.top();
        queue.pop();

        visited[node.id] = 1;

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                if (node.dist + map[node.id][i] < d[i]) {
                    d[i] = node.dist + map[node.id][i];
                    c[i] = c[node.id];
                    w[i] = w[node.id] + man[i];
                    queue.emplace(i, d[i]);
                }
                else if (node.dist + map[node.id][i] == d[i]) {
                    c[i] += c[node.id];
                    w[i] = max(w[i], w[node.id] + man[i]);
                }
            }
        }
    }

    cout << c[C2] << ' ' << w[C2] << endl;
}
