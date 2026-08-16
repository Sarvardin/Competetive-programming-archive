#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Массив всех счастливых чисел до 1000
    vector<int> lucky_numbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    // Проверяем, делится ли n хотя бы на одно из них
    for (int lucky : lucky_numbers) {
        if (n % lucky == 0) {
            cout << "YES" << endl;
            return 0; // Нашли делитель — сразу выходим
        }
    }

    // Если цикл закончился и ни один делитель не подошел
    cout << "NO" << endl;
    return 0;
}