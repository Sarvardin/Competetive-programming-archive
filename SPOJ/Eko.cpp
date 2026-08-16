#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chop(int x, int num, const vector<int>& arr) {
    long long wood = 0;
    for (int t : arr) {
        if (t > x) {
            wood += (t - x);
        }
    }
    return wood >= num; // Нам нужно "хотя бы M", поэтому >=
};



int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> trees(n);
    for (int i = 0; i < n; i++) {cin >> trees[i];}
    int a = 0, b = 1000000000, ans = 0;
    while (a <= b) {
        int k = a + (b-a) / 2;
        if (chop(k, m, trees)) {
            ans = k;
            a = k+1;
        } else {
            b = k-1;
        }
    }
    cout << ans << endl;
    return 0;
}
