class Solution {
private:
    static constexpr int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if (grid[0][0] != 0) return -1;
        q.push({0, 0});
        grid[0][0] = 2;
        int n = grid.size();
        int m = n;
        int cnt = 1;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                pair<int, int> now = q.front();
                q.pop();
                if (now.first == n - 1 && now.second == m - 1) {
                    return cnt;
                }
                for (int j = 0; j < 8; ++j) {
                    int nx = now.first + dir[j][0];
                    int ny = now.second + dir[j][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            ++cnt;
        }
        return -1;
    }
};