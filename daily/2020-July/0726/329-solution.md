# 每日一题——329.矩阵中的最长递增路径（Hard）
## 这题是一道记忆化DFS/拓扑排序/DP题，第一种方法实现难度不高，但是后两种实现很难想到

## 题目：
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

## 解法一（记忆化DFS）：
因为直接用DFS来暴搜的话时间复杂度是指数级别的，明显困难难度下回出现TE，所以此处需要借用一个二维数组来记录每个位置是否已经被计算过，该位置如果不为0，则无需重新计算。
注意，此处DFS需要设置有返回值，当判断下一跳合法（不超过区间且大于当前数字）则讲memo数组本位置的值变更为现有值和下一跳DFS结果的最大值。

```
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
```
### 最离谱的是当时dfs传入的vector<vector<int>> &mat数组没有加&导致是值传递，效率慢了很多，一直超时。这点以后得切记。
