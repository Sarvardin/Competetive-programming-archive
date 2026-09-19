#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Ускорение ввода/вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> house(n);
    pair<int, int> start, end_pos;

    // Считываем карту и ищем точки A и B
    for (int i = 0; i < n; i++) {
        cin >> house[i];
        for (int j = 0; j < m; j++) {
            if (house[i][j] == 'A') start = {i, j};
            if (house[i][j] == 'B') end_pos = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> previous_step(n, vector<char>(m, 0));

    queue<pair<int, int>> q;
    
    // Инициализация старта
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    // Основной цикл BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Если дошли до B, прерываем поиск
        if (x == end_pos.first && y == end_pos.second) {
            found = true;
            break;
        }

        // ВВЕРХ (x уменьшается)
        if (x - 1 >= 0 && !visited[x - 1][y] && house[x - 1][y] != '#') {
            visited[x - 1][y] = true;
            previous_step[x - 1][y] = 'U';
            q.push({x - 1, y});
        }
        
        // ВНИЗ (x увеличивается)
        if (x + 1 < n && !visited[x + 1][y] && house[x + 1][y] != '#') {
            visited[x + 1][y] = true;
            previous_step[x + 1][y] = 'D';
            q.push({x + 1, y});
        }
        
        // ВЛЕВО (y уменьшается)
        if (y - 1 >= 0 && !visited[x][y - 1] && house[x][y - 1] != '#') {
            visited[x][y - 1] = true;
            previous_step[x][y - 1] = 'L';
            q.push({x, y - 1});
        }
        
        // ВПРАВО (y увеличивается)
        if (y + 1 < m && !visited[x][y + 1] && house[x][y + 1] != '#') {
            visited[x][y + 1] = true;
            previous_step[x][y + 1] = 'R';
            q.push({x, y + 1});
        }
    }

    // Вывод результата
    if (found) {
        cout << "YES\n";
        
        string path = "";
        int curr_x = end_pos.first;
        int curr_y = end_pos.second;

        // Отматываем путь от B к A по массиву previous_step
        while (curr_x != start.first || curr_y != start.second) {
            char p = previous_step[curr_x][curr_y];
            path += p;

            // Делаем шаг назад
            if (p == 'U') curr_x++;
            else if (p == 'D') curr_x--;
            else if (p == 'L') curr_y++;
            else if (p == 'R') curr_y--;
        }

        // Так как шли с конца, разворачиваем строку
        reverse(path.begin(), path.end()); 

        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }


    

    return 0;
}