#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    
    

    cin >> n;
    vector<int> boys(n);
    for(int i = 0; i < n; i++) {
        cin >> boys[i];
    }
    cin >> m;
    vector<int> girls(m);
    for(int j = 0; j < m; j++) {
        cin >> girls[j];
    }


    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if(abs(boys[i] - girls[j]) <= 1) {
            ans++; i++; j++;
        } else if(boys[i] < girls[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
    
}