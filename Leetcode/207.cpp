class Solution {
public:
    bool possible = true;

    void dfs(int s, vector<int>& visited, vector<vector<int>>& graph) {
        visited[s] = 1;

        for(auto u : graph[s]) {
            if (visited[u] == 1) {
                possible = false;
            }
            if (visited[u] == 0) {
                dfs(u, visited, graph);
            }



        }
        visited[s] = 2;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        possible = true;

        vector<int> dist(numCourses);

        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (dist[i] == 0) {
                dfs(i, dist, adj);
            }
        }

        return possible;
    }
};