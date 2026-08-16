#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(1000);
    for(int i = 0; i < n; i++) { cin >> array[i];}
    vector<int> count(1001);
    for(int j = 0; j < n; j++) {
        count[array[j]] += 1;
    }
    int max = 0, ans = 0;
    for(int i = 1; i <= 1000; i++) {
        if(count[i] != 0) {
            ans++;
            if(count[i] > max) max = count[i];
        }
    }
    cout << max << " " << ans << endl;
}