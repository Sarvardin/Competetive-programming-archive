#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Простая функция DFS: передаем карту и visited по ссылке (&)
void dfs(int x, int y, int n, int m, vector<vector<bool>>& vis, const vector<string>& home) {
    if(vis[x][y]) return;
    vis[x][y] = true;

    if (x - 1 >= 0 && home[x-1][y] == '.') dfs(x-1, y, n, m, vis, home);
    if (x + 1 < n  && home[x+1][y] == '.') dfs(x+1, y, n, m, vis, home);
    if (y - 1 >= 0 && home[x][y-1] == '.') dfs(x, y-1, n, m, vis, home);
    if (y + 1 < m  && home[x][y+1] == '.') dfs(x, y+1, n, m, vis, home);
}

int main() {
    int n, m;
    cin >> n >> m;

    // Вектор из n строк
    vector<string> house(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Считываем n строк целиком (cin сам считывает строку до пробела/переноса)
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Если это пол и мы там еще не были — запускаем DFS
            if (house[i][j] == '.' && !visited[i][j]) {
                rooms++;
                dfs(i, j, n, m, visited, house);
            }
        }
    }

    cout << rooms << endl;

    return 0;
}