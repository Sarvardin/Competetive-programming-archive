class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<bool>>& vis, const vector<vector<char>>& home) {
    if(vis[x][y]) return;
    vis[x][y] = true;

    if (x - 1 >= 0 && home[x-1][y] == '1') dfs(x-1, y, n, m, vis, home);
    if (x + 1 < n  && home[x+1][y] == '1') dfs(x+1, y, n, m, vis, home);
    if (y - 1 >= 0 && home[x][y-1] == '1') dfs(x, y-1, n, m, vis, home);
    if (y + 1 < m  && home[x][y+1] == '1') dfs(x, y+1, n, m, vis, home);
};

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

    
        

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(i, j, n, m, visited, grid);
                }
        }
    }
    return islands;
    }
};