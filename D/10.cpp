#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> s(m);
    for(int i = 0; i < m; i++) {
        cin >> s[i];
    }

    vector<int> dp(m, 0);
    vector<int> parent(m, -1);

    for(int i = 0; i < n; i++) {

        int best_len = 0;
        int best_parent = -1;

        for(int j = 0; j < m; j++) {
            if(a[i] > s[j]) {
                if(dp[j] > best_len) {
                    best_parent = j;
                    best_len = dp[j];
                }
            }
            if(a[i] == s[j]) {
                dp[j] = best_len + 1;
                parent[j] = best_parent;
            }
        }
    }

    
    auto max_sub = max_element(dp.begin(), dp.end());
    int best_end = distance(dp.begin(), max_sub);

    cout << *max_sub << endl;

    if (*max_sub > 0) {
        int curr = best_end;
        vector<int> result;
    
        while(curr != -1) {
            result.push_back(s[curr]);
            curr = parent[curr];
        }

        reverse(result.begin(), result.end());

        for(auto i : result) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
    
    

}