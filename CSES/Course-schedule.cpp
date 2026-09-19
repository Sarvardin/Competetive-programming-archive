#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool possible = true;

void dfs(int s, vector<int>& visited, vector<vector<int>>& graph, vector<int>& res) {
    visited[s] = 1;

    for(auto u : graph[s]) {
    if (visited[u] == 1) {
        possible = false;
    }
    if (visited[u] == 0) {
        dfs(u, visited, graph, res);
    }



    }
    visited[s] = 2;
    res.push_back(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> dist(n+1);

    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0) {
            dfs(i, dist, adj, result);
        }
    }

    if (possible) {
        reverse(result.begin(), result.end());
        for (auto i : result) {
            cout << i << " ";
        }
        return 0;
    }
    cout << "IMPOSSIBLE";
}