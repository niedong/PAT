#include <bits/stdc++.h>

using namespace std;

int dfs(const vector<vector<int>>& graph, vector<bool>& visited, int s, int c) {
    if (visited[s]) return 0;

    int res = 1, n = graph.size() - 1;
    visited[s] = true;
    for (int i = 1; i <= n; ++i) {
        if (i == s || i == c) continue;
        if (!visited[i] && graph[s][i]) res += dfs(graph, visited, i, c);
    }

    return res;
}

int repair(const vector<vector<int>>& graph, int c) {
    int res = -1, v = 0, n = graph.size() - 1;
    vector<bool> visited(n + 1);
    while (v != n - 1) {
        for (int i = 1; i <= n; ++i) {
            if (i == c) continue;
            if (!visited[i]) {
                v += dfs(graph, visited, i, c), ++res;
            }
        }
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    while (m--) {
        int s, e;
        cin >> s >> e;
        graph[s][e] = graph[e][s] = 1;
    }

    while (k--) {
        int c;
        cin >> c;
        auto g = graph;
        for (int i = 1; i <= n; ++i) g[i][c] = g[c][i] = 0;
        cout << repair(g, c) << endl;
    }
}
