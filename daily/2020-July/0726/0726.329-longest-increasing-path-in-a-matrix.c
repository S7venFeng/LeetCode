class Solution {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        public:
        int dfs(vector<vector<int>> &memo, int row, int col, vector<vector<int>> &mat) {
            if (memo[row][col]) return memo[row][col];
            memo[row][col]++;
            for (int i = 0; i < 4; ++i) {
                int nextR = row + dir[i][0];
                int nextC = col + dir[i][1];
                if (nextR < 0 || nextR > mat.size() - 1 || nextC < 0 || nextC > mat[0].size() - 1) continue;
                if (mat[nextR][nextC] > mat[row][col]) {
                    memo[row][col] = max(memo[row][col], dfs(memo, nextR, nextC, mat) + 1);
                }
            }
            return memo[row][col];
        }
        int longestIncreasingPath(vector<vector<int>>& mat) {
            if (mat.size() == 0 || mat[0].size() == 0 ) return 0;
            int n = mat.size();
            if (!n) return 0;
            int m = mat[0].size();
            vector<vector<int>> memo(n, vector<int>(m));
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ans = max(ans, dfs(memo, i, j, mat));
                }
            }
            return ans;
        }
};