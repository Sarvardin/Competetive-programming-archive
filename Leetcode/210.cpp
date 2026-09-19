class Solution {
public:
    bool possible = true;

    void dfs(int s, vector<int>& visited, vector<vector<int>>& graph, vector<int>& res) {
        visited[s] = 1;

        for(auto u : graph[s]) {
            if (visited[u] == 1) {
                possible = false;
            }
            if (visited[u] == 0) {
                dfs(u, visited, graph, res);
            }



        }
        visited[s] = 2;
        res.push_back(s);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        possible = true;

        vector<int> dist(numCourses);

        vector<int> result;

        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (dist[i] == 0) {
                dfs(i, dist, adj, result);
            }
        }

        if (possible) {
            reverse(result.begin(), result.end());
            return result;
        }
        return {};
    }

};