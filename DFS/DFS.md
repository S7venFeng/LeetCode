# DFS搜索系列题





## 岛屿系列题：

#### [1254. 统计封闭岛屿的数目](https://leetcode-cn.com/problems/number-of-closed-islands/)

有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。

我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。

如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。

请返回封闭岛屿的数目。

 示例 1：

输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
输出：2
解释：
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
示例 2：

输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
输出：1
示例 3：

输入：grid = [[1,1,1,1,1,1,1],
             [1,0,0,0,0,0,1],
             [1,0,1,1,1,0,1],
             [1,0,1,0,1,0,1],
             [1,0,1,1,1,0,1],
             [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
输出：2

## 思路：

网格搜索题，该题是搜索入口是为0的点，搜索的附加条件是碰到边界的情况就终止，碰到1的情况认为是成功，当dfs递归搜索的4个方向都是1时认为全0的岛屿被

水域所包围，答案数加1.

**此题有2个点需要特别注意：**

1. **需要用一个visited的数组来避免dfs重复搜索，但是用visited数组的话，代码写起来比较冗余，此处可以用一个常用技巧，将遍历过的位置的0变成1，这样我们判断时就不会再次进行搜索，因为搜索位置值为1时我们会直接返回true，表示该方向搜索正确，是被1围绕的**
2. **搜索四个方向时不能碰到边界就返回false，此时应该把四个方向都搜索完再返回正确，反过来想，如果只搜索了部分方向剩余的方向没有搜索和标记，在外层循环判断该位置是否为0是会再次进入，这样得出的结果会多**

```c++
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
```



## 记忆化DFS题目：

### 此类题目是基于DFS的基础上面做了一个记忆化的保存操作，这么做的原因是dfs递归过程中做了很多次重复计算，耗费了非常多的时间，如果在计算时能保存下来，下次遇到直接读取则会加速非常多。通过记忆化递归来避免重复操作，这个过程也是动态规划的思想体现。

### 题目一：

#### [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

### 思路一：

​	此题思路比较容易想到，就是从入口根节点开始，依次往下遍历，遍历的过程中我们有两种选择：

1. 不选择根节点，此时就可以选择根节点的左右儿子节点
2. 选择根节点，此时就只能选择四个孙子    

每个节点都有以上两种情况，我们把2种情况的结果取max即使这个节点的遍历结果，然后通过一个哈希表来保存结果（key是node，values是最大值），用哈希表的原因是我们能够在O(1)的时间内索引到某个节点的最大值

```c++
class Solution {
public:
    unordered_map<TreeNode *, int> m;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        if (m[root]) return m[root];
        int money = root->val;
        if (root->left) {
            money += dfs(root->left->left) + dfs(root->left->right);
        }
        if (root->right) {
            money += dfs(root->right->left) + dfs(root->right->right);
        }
        money = max(money, dfs(root->left) + dfs(root->right));
        m[root] = money;
        return money;
    }
    int rob(TreeNode* root) {
		return dfs(root);
    }
};
```

### 思路二：

按照刚才的思路我们做进一步的优化，每个节点可选择偷或者不偷两种状态：

- 当前节点选择偷时，两个孩子节点就不能偷
- 当前节点选择不偷时，两个孩子节点的钱贡献给结果（两个孩子可以选择偷或者不偷）

如果使用1个一维数组来表示每个节点的状态，vector<int> res,.0 代表偷，1 代表不偷
任何一个节点能偷到的最大钱的状态可以定义为

当前节点选择不偷：当前节点能偷到的最大钱数 = 左孩子能偷到的钱 + 右孩子能偷到的钱
当前节点选择偷：当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数

所以每个节点的结构就是res[0]和res[1]的最大值

```c++
class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2);
        }
        vector<int> res(2);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 偷
        res[0] = root->val + left[1] + right[1];
        // 不偷
        res[1] = max(left[0], left[1]) + max(right[0], right[1]); 
        return res;
    }
    int rob(TreeNode* root) {
		vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};
```

