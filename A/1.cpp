#include <iostream>
using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    long long ans = (long long)((n + a - 1) / a) * ((m + a - 1) / a);
    cout << ans << '\n';
    return 0;
}
