#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

vector<vector<int>> adj_rev; // Обратный граф для проверки достижимости N
vector<bool> can_reach_n;   // Флаг: можно ли из вершины i дойти до N

// DFS по обратному графу от вершины N
void dfs_rev(int u) {
    can_reach_n[u] = true;
    for (int v : adj_rev[u]) {
        if (!can_reach_n[v]) {
            dfs_rev(v);
        }
    }
}

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    adj_rev.resize(n + 1);
    can_reach_n.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        
        // Разворачиваем ребро для обратного графа: v -> u
        adj_rev[v].push_back(u);
    }

    // 1. Запускаем DFS из вершины N по обратному графу.
    // Это за один раз пометит все вершины, из которых в обычном графе МОЖНО дойти до N.
    dfs_rev(n);

    // 2. Инициализация расстояний для поиска МАКСИМУМА
    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;

    // 3. Основной цикл Беллмана-Форда (N - 1 итерация)
    for (int i = 1; i <= n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != -INF) {
                if (dist[e.u] + e.w > dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }
    }

    // 4. Дополнительные N итераций для распространения положительных циклов.
    // Если вершина увеличивается и при этом до нее МОЖНО дойти из 1,
    // а из нее МОЖНО дойти до N (can_reach_n == true) -> ответ -1.
    bool infinite_score = false;

    for (int i = 1; i <= n; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != -INF) {
                if (dist[e.u] + e.w > dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    
                    // Проверяем: влияет ли этот бесконечный прирост на ответ в N?
                    if (can_reach_n[e.v]) {
                        infinite_score = true;
                    }
                }
            }
        }
    }

    // 5. Вывод результата
    if (infinite_score) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}