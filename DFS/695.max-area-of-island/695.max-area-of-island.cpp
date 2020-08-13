class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int &cur) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            if (grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                cur++;
                dfs(grid, nx, ny, cur);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = 0;
                if (grid[i][j] == 1) {
                    cur = 1;
                    grid[i][j] = 2;
                    dfs(grid, i, j, cur);
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};