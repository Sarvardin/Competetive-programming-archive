#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    long long INF = 1e18;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<long long, int>> q;

    vector<bool> visited(n + 1, false);

    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for(auto u : adj[a]) {
            int b = u.first, w = u.second;
            if(dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}
