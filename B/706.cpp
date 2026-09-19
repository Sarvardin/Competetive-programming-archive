#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> shops(n);
    for (int i = 0; i < n; i++) {
        cin >> shops[i];
    }
    int q;
    cin >> q;
    vector<int> coins(q);
    for (int i = 0; i < q; i++) {
        cin >> coins[i];
    }
    sort(shops.begin(), shops.end());
    for (int j : coins) {
        int a = 0, b = n-1;
        while (a <= b) {
            int k = (a+b)/2;
            if (shops[k] <= j) a = k+1;
            else b = k-1;
        }
        cout << a << "\n";

    }


}