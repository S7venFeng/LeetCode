class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> isVisited(n, vector<bool>(m));
        vector<vector<int>> dist(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!mat[i][j]) {
                    q.push({i, j});
                    isVisited[i][j] = 1;
                }
            }
        }
        while (q.size()) {
            auto now = q.front();
            q.pop();
            mat[now.first][now.second] = dist[now.first][now.second];
            for (int k = 0; k < 4; ++k) {
                int ni = now.first + dir[k][0];
                int nj = now.second + dir[k][1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (!isVisited[ni][nj] && mat[ni][nj] == 1) {
                    isVisited[ni][nj] = true;
                    dist[ni][nj] = dist[now.first][now.second] + 1;
                    q.emplace(ni, nj);
                }
            }
        }
        return mat;
    }
};