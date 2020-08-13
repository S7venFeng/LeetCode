class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int x, int y, vector<vector<int>>& grid, int color, vector<int> isVistied, vector<vector<int>>& ans) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        int temp = grid[x][y];
        if (x == 0 || y == 0 || x == grid.size() - 1|| y == grid[0].size() - 1) {
            ans[x][y] = color;
        }
        isVistied[x * grid[0].size() + y] = 1;
        for (int i = 0; i < 4; ++i) {
            if (x + dir[i][0] >= 0 && x + dir[i][0]  < grid.size() && y + dir[i][1] >= 0 && y + dir[i][1] < grid[0].size() && 0 == isVistied[(x + dir[i][0]) * grid[0].size() + y + dir[i][1]]) {
                if (grid[x + dir[i][0]][y + dir[i][1]] != temp) {
                    ans[x][y] = color;
                } else {
                    dfs(x + dir[i][0], y + dir[i][1], grid, color, isVistied, ans);
                }
            }
        }
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<int> isVistied(grid[0].size() * grid.size());
        vector<vector<int>> ans(grid.begin(), grid.end());
        dfs(r0, c0, grid, color, isVistied, ans);
        return ans;
    }
};