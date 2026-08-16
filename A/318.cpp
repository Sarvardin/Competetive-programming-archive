#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (n % 2 == 0) 
    {
        if (k <= n / 2) 
        {
            cout << 1 + 2 * (k - 1) << '\n';
        } 
        else 
        {
            cout << 2 * (k - n / 2) << '\n';
        }
    }
    else {
        if (k <= (n + 1) / 2) 
        {
            cout << 1 + 2 * (k - 1) << '\n';
        } 
        else 
        {
            cout << 2 * (k - (n + 1) / 2) << '\n';
        }
    }
}