#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    long long ans = 0;
    
    while (n >= 3) {
        long long k = n / 3;
        ans += k; // Хао всегда забирает ровно кусок k
        
        int rem = n % 3;
        if (rem == 0) {
            n = k;
        } else if (rem == 1) {
            n = k + 1;
        } else { // rem == 2
            n = k + 2; // Вот тут мы оставляем больше на завтра!
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}