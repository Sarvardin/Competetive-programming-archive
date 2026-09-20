#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> days(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    for (int i = 0; i < n; i++) {

        t -= (86400 - days[i]);

        if (t <= 0) {
            cout << i+1;
            return 0;
        }
    }

}