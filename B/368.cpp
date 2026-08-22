#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> s;
    vector<int> nums(n);
    for(int i = n - 1; i >= 0; i--) {
        s.insert(a[i]);
        nums[i] = s.size();
    }

    for(int k = 1; k <= m; k++) {
        int temp;
        cin >> temp;
        cout << nums[temp-1] << endl;
    }
    return 0;

}