class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x > grid.size() - 1 || x < 0 || y < 0 || y > grid[0].size() - 1) {
            return false;
        }
        if (grid[x][y] == 1) {
            return true;
        }
        grid[x][y] = 1;
        int res  = 0;
        for (int i = 0; i < 4; ++i) {
            res += dfs(grid, x + dir[i][0], y + dir[i][1]);
        }
        if (res == 4) {
            return true;
        } else {
            return false;
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (0 == grid[i][j]) {
                    if(true == dfs(grid, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};