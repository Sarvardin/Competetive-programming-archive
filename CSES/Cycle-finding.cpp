#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    bool cycle = false;
    int pos = 0;
   // long long INF = 1e18;
    cin >> n >> m;


    vector<long long> distance(n+1, 0);
    vector<int> parent(n+1, -1);


    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};

    }

    for (int i = 1; i <= n-1; i ++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;

                if (distance[a] + w < distance[b]) {
                    distance[b] = distance[a] + w;
                    parent[b] = a;
                    pos = b;

                }


        }
    }

    for (auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;

        if (distance[b] > distance[a] + w) {
            parent[b] = a;
            pos = b;
            cycle = true;
        }
    }
    if (cycle) {
        cout << "YES" << "\n";

        for (int i = 0; i < n; i++) {
            pos = parent[pos];
        }

        vector<int> path;
        int curr = pos;
        do {
            path.push_back(curr);
            curr = parent[curr];
        } while (curr != pos);
        path.push_back(pos);

        reverse(path.begin(), path.end());
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << "NO";
    return 0;

    }

