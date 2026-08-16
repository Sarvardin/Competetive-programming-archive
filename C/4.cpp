#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string name;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (mp.count(name) == 0) {
        
        cout << "OK\n";
        mp[name] = 1;
        } else {
            cout << name + to_string(mp[name]) << '\n';
            string new_name = name + to_string(mp[name]);
            mp[new_name] = 1;
            mp[name]++;
        }
    }
}