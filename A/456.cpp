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
    int ans = 0;
    for(int j = 0; j < n-1; j++) {
        if(array[j].second > array[j+1].second) {
            ans = 1;
        }
    }
    if(ans == 1) {
        cout << "Happy Alex";
    } else {
        cout << "Poor Alex";
    }
    return 0;
}