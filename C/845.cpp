#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> array(n);

    for(int i = 0; i < n; i++) {
        cin >> array[i].first >> array[i].second;

    }

    sort(array.begin(), array.end());

    int tv1 = -1, tv2 = -1, ans = 0;

    for(int i = 0; i < n; i++) {
        if(array[i].first > tv1) tv1 = array[i].second;
        else if(array[i].first > tv2) {
            tv2 = array[i].second;
        } else { ans = 1;}

    }
    if(ans == 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}