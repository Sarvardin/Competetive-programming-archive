#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> topo_order;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    topo_order.push_back(v);
}

vector<bitset<MAXN>> reach;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;

    adj.resize(n + 1);
    visited.resize(n + 1, false);
    reach.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(topo_order.begin(), topo_order.end());

    for (int v : topo_order) {
        reach[v][v-1] = 1;
        for (int u : adj[v]) {
            reach[v] |= reach[u];
        }
    }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        if (reach[a][b - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}