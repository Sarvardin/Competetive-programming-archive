#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> cuts{a, b, c};
    vector<int> dp(n+1, -1);
    dp[0] = 0;

     for (int x = 1; x <= n; x++) {
        for (int c : cuts) {
            
            if (x - c >= 0 && dp[x - c] != -1) {
                dp[x] = std::max(dp[x], dp[x - c] + 1);
                          
            }
        }
    
     }
     cout << dp[n];
    return 0;
}