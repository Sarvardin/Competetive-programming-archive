#include <iostream>
using namespace std;

long long solve(long long n, long long a, long long b) {
    long long full = n / 3;
    long long rem = n % 3;

    long long ans = full * min(3 * a, b);

    if (rem == 1)
        ans += min(a, b);
    else if (rem == 2)
        ans += min(2 * a, b);

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long n, a, b;
        cin >> n >> a >> b;

        cout << solve(n, a, b) << '\n';
    }
}