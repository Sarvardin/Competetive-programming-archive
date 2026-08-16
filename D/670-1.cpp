#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция проверки: можно ли испечь x печенек?
bool can_bake(long long x, int n, long long k, const vector<int>& a, const vector<int>& b) {
    long long needed_powder = 0;
    for (int i = 0; i < n; i++) {
        long long total_needed = x * a[i];
        if (total_needed > b[i]) {
            needed_powder += (total_needed - b[i]);
        }
        // Если уже потратили больше порошка, чем есть - дальше считать нет смысла
        if (needed_powder > k) return false;
    }
    return needed_powder <= k;
}

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // Бинарный поиск по ответу
    // Минимальное число печенек — 0, максимальное — 2e9 (с запасом)
    long long low = 0, high = 2000000000;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (can_bake(mid, n, k, a, b)) {
            ans = mid;      // Если можем испечь mid, запоминаем
            low = mid + 1;  // Пробуем испечь больше
        } else {
            high = mid - 1; // Если нет, уменьшаем цель
        }
    }

    cout << ans << endl;

    return 0;
}
