#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// dp[u] — макс. число городов от u до n
// p[u]  — куда идти из u дальше, чтобы получить макс. путь
vector<int> dp;
vector<int> p;
vector<vector<int>> adj;

int dfs(int u, int n) {
    // 1. Базовый случай: дошли до целевого города N
    if (u == n) {
        return dp[u] = 1;
    }

    // 2. Мемоизация: если уже считали — возвращаем
    if (dp[u] != -1) {
        return dp[u];
    }

    int max_cities = -INF;
    int best_next = -1;

    // 3. Перебираем всех соседей
    for (int v : adj[u]) {
        int res = dfs(v, n);

        // Если из v можно дойти до n
        if (res > 0) {
            if (1 + res > max_cities) {
                max_cities = 1 + res;
                best_next = v; // запоминаем лучший следующий шаг
            }
        }
    }

    p[u] = best_next;
    return dp[u] = max_cities;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    dp.assign(n + 1, -1);
    p.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Запускаем DFS из начального города 1
    int ans = dfs(1, n);

    // Если ответ отрицательный — путь до N не существует
    if (ans < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Выводим длину пути
    cout << ans << "\n";

    // Восстанавливаем путь по массиву p
    int curr = 1;
    while (curr != -1) {
        cout << curr << " ";
        curr = p[curr];
    }
    cout << "\n";

    return 0;
}