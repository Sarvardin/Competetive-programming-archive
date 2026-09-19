#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (1900 <= n) {
            cout << "Division 1" << endl;;
            continue;
        }
        if (1600 <= n && n <= 1899) {
            cout << "Division 2" << endl;
            continue;
        }
        if (1400 <= n && n <= 1599) {
            cout << "Division 3" << endl;
            continue;
        }
        if (n <= 1399) {
            cout << "Division 4" << endl;

        }






    }
    return 0;
}