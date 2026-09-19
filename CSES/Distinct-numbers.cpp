#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        s.insert(nums[i]);
    }
    cout << s.size();
    return 0;
}