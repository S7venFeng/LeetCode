class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        int n = rooms.size();
        if (!n) return;
        int m = rooms[0].size();
        vector<vector<int>> dis(rooms.begin(), rooms.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = now.first + dir[i][0];
                int ny = now.second + dir[i][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || rooms[nx][ny] == -1) continue;
                if (dis[now.first][now.second] + 1 < dis[nx][ny]) {
                    dis[nx][ny] = dis[now.first][now.second] + 1;
                    rooms[nx][ny] = dis[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    }
};