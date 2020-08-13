class Solution {
private:
    static const int constexpr dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>> &cur) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
            if (grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                cur.push_back({nx, ny});
                dfs(grid, nx, ny, cur);
            }
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> v;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    vector<pair<int, int>> cur;
                    cur.push_back({i, j});
                    dfs(grid, i, j, cur);
                    for (auto &x : cur) {
                        x.first -= i;
                        x.second -= j;
                    }
                    sort(cur.begin(), cur.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
                        if (p1.first == p2.first) {
                            return p1.second < p2.second;
                        }
                        return p1.first < p2.first;
                    });
                    for (auto x : cur) {
                    }
                    v.push_back(cur);
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v.size();
    }
};