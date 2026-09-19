#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Пара: {вес_ребра, вершина}
using pii = pair<int, int>;

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Список смежности: adj[u] хранит пары {v, weight}
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Граф неориентированный
    }

    // Мин-куча (Min-Heap): {вес, вершина}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n + 1, false);

    long long mst_weight = 0;
    int visited_count = 0;

    // Старт с вершины 1 (стоимость подключения = 0)
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        // Если вершина уже добавлена в MST — пропускаем (ленивое удаление)
        if (visited[u]) continue;

        // Включаем вершину в остовное дерево
        visited[u] = true;
        mst_weight += w;
        visited_count++;

        // Добавляем в кучу все ребра, ведущие к еще не посещенным вершинам
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    // Если в остов вошли все N вершин — дерево успешно построено
    if (visited_count != n) {
        cout << "IMPOSSIBLE\n"; // Граф несвязен
    } else {
        cout << mst_weight << "\n";
    }

    return 0;
}