#include <iostream>
#include <vector>

using namespace std;

// 2^30 > 10^9, поэтому 30 степеней двойки нам хватит с запасом
const int LOG = 30;

int main() {
    // Ускорение ввода-вывода (обязательно для 2*10^5 запросов!)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // up[j][i] — где окажемся, если из планеты i сделаем 2^j прыжков
    vector<vector<int>> up(LOG, vector<int>(n + 1));

    // 1. Считываем базовые телепорты (прыжки на 2^0 = 1 шаг)
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
    }

    // 2. Предрасчёт таблицы (Dynamic Programming / Binary Lifting)
    // 2^j шагов = (2^(j-1) шагов) + ещё (2^(j-1) шагов)
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // 3. Обработка запросов
    while (q--) {
        int x, k;
        cin >> x >> k;

        // Разбираем k по битам
        for (int j = 0; j < LOG; j++) {
            // Если j-й бит установлен (1 << j — это 2^j)
            if ((k >> j) & 1) {
                x = up[j][x];
            }
        }

        cout << x << "\n";
    }

    return 0;
}