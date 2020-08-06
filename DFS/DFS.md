# DFS  & BFS搜索系列题

DFS和BFS是用的最多的搜索手段，两种方法在搜索维度上有较大的不同，具体不同如下：

1. DFS搜索空间复杂度依赖于搜索深度，而搜索过程中会用到栈来保存，如果大于C++目前的栈容量（4Mb，约10w深度）就会爆栈；另外DFS时间复杂度最坏情况下特别差
2. BFS搜索空间复杂度是指数级别的，因为每次搜索的是一层，一层加上后面一层，另外**BFS有最短最小的属性，一般在求图的最小路径等问题上会率先采用**

DFS写起来比BFS简单一些，但是一定要注意题目规模，如果题目规模较大，尽量采用BFS

## 搜索经典模板题：

#### [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
    9  20
    /  \
    15   7

 返回它的最小深度  2.

### 思路一（DFS）：

这题是一道经典的数遍历题，题目要求是让我们找根节点到叶子节点的最小深度，此处需要根据几个条件来判断下：

1. 无当前节点
2. 当前节点只有左子树或者右子树
3. 当前节点两个子树都有

注意第二个条件下，两边只返回左子树或者右子树的深度（不是取min，因为一边深度是0），第三个条件是取两个子树的最小深度。

知道以上条件后递归调用即可

```c++
class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        int l = 0;
        int r = 0;
        if (root->left) {
            l = dfs(root->left) + 1;
        } else {
            l = INT_MAX;
        }
        if (root->right) {
            r = dfs(root->right) + 1;
        } else {
            r = INT_MAX;
        }
        return min(l, r);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return dfs(root);
    }
};
```

简捷版：

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->right) {
            return minDepth(root->left) + 1;
        }
        if (!root->left && root->right) {
            return minDepth(root->right) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```

**时间复杂度：**我们会访问到所有节点，所以此处的时间复杂度是**O(N)**

**空间复杂度：** 最坏的情况下，该树根节点只有一个子树，深度就是所有节点的个数，空间复杂度为**O(N)**；最好的情况下，该树节点是个平衡树，这时我们的过程栈只需要保存它的高度个节点logN，所以空间复杂度是**O(logN)**

### 思路二（BFS）：

用BFS来做的话这道就是最简单的模板题，先将根节点推入队列，然后开始循环判断队列是否为空，不为空则依次出队，注意出队是要保存下当前层数（也就是深度），每一层ans++，当出队的当前节点是叶子节点时，就代表我们已经找到了最小的深度了（这就是BFS的最小属性，一旦找到第一个符合条件的，必定该节点是最短路径）此时直接返回ans即可。

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int cnt = q.size();
            ans++;
            while (cnt) {
                TreeNode* now = q.front();
                q.pop();
                if (!now->left && !now->right) {
                    return ans;
                }
                if (now->left) {
                    q.push(now->left);
                }
                if (now->right) {
                    q.push(now->right);
                }
                cnt--;
            }
        }
        return ans;
    }
};
```

**时间复杂度**：最坏的情况下，这是一颗平衡树，以为着我们每层都得遍历，这样我们遍历了除了最后一层的N/2个节点，时间复杂度**O(N)**

**空间复杂度**：用了一个队列来保存N个节点，同样是**O(N)**

#### [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

### 这是我做到非常差的一道题目，主要是使用DFS和BFS不注意的话都会超时

### 思路一（DFS）：

题目意思很清楚，让你求把N个完全平方数的和凑到和目标数字相同，然后要让这个N最小。很明显，公式可以列为：F(n) = F(n-i) + 1

这个公式我们可以用DFS的方式来解，因为F(n)和F(n - i)其实是存在递推关系的，这也是DP问题的雏形，此处我们列举所有平方小于n的i，将两者的差值

代入到DFS递归方法里面去计算，一旦满足n-i的值等于0时意味着我们找到了一个符合条件的情况。**此时需要注意，这并不是最优解（DFS特征，需要搜索完），我们需要保存下来，每次符合条件时都要去判断下是否能够更新答案，搜索完成后的最优解才能出现**

为了避免超时，这里我们要用到记忆化数组来保存中间计算的结果，当出现相同的数字时，我们如果已经计算过这个数字的最优平方数则直接返回，无需计算

PS：奇怪的是，此处我用unordered_map保存中间结果会超时，改成vector就行了

```c++
class Solution {
public:
    int dfs(vector<int> &nums, int n, vector<int> &mo) {
        if (n == 0) return 0;
        if (mo[n]) {
            return mo[n];
        }
        int mn = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (n - nums[i] < 0) continue;
            mn = min(mn, 1 + dfs(nums, n - nums[i], mo));
        }
        mo[n] = mn;
        return mn;
    }

    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; (i * i) <= n; ++i) {
            nums.push_back(i * i);
        }
        vector<int> mo(n + 1);
        return dfs(nums, n, mo);
    }
};
```

**思路二（BFS）：**

此题BFS也算是模板BFS，可以加入贪心策略来做，此处还是按照常规的模板来实现的。思路是从0开始自顶向下来搜索，把满足平方小于n的数都加上当前的数（0），结果放入队列，下一层取出所有队列里面的数继续上述操作，当找到第一个满足条件的数时此时的层数就是答案。

**需要注意的是，此处同样要用一个记忆化数组来保存中间计算过的数字，当计算过我们则不需要再压入队列了**

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for (int i = 1; i * i <= n; ++i) {
            v.push_back(i * i);
        }
        queue<int> q;
        vector<bool> isVisited(n + 1);
        q.push(0);
        isVisited[0] = true;
        int ans = 0;
        while (!q.empty()) {
            int cnt = q.size();
            ans++;
            while (cnt) {
                int now = q.front();
                q.pop();
                if (now == n) {
                    return ans - 1;
                }
                for (int i = v.size() - 1; i >= 0; --i) {
                    if (v[i] + now > n || isVisited[v[i] + now]) continue;
                    isVisited[v[i] + now] = true;
                    q.push(v[i] + now);
                }
                --cnt;
            }
        }
        return ans;
    }
};
```

#### [733. 图像渲染](https://leetcode-cn.com/problems/flood-fill/)

有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

示例 1:

输入: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。

注意:

- image 和 image[0] 的长度在范围 [1, 50] 内。
- 给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
- image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

### 经典中的经典，所有DFS & BFS网格搜索的起点！不知道为什么中文把Flood Fill翻译成了图像渲染

### 思路一（DFS）：

代码待补充

### 思路二（BFS）：

BFS模板题，此处需要注意下保存当前节点已经被遍历过，如果不保存的话会出现4个方向又走回来的情况，会出现死循环。

出现与起始点相同又能到达的点我们就把它染色即可

```c++
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        pair<int, int> begin = {sr, sc};
        int srColor = image[sr][sc];
        vector<vector<bool>> isVisited(image.size(), vector<bool>(image[0].size()));
        q.push(begin);
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            isVisited[now.first][now.second] = true;
            image[now.first][now.second] = newColor;
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next;
                next.first = now.first + dir[i][0];
                next.second = now.second + dir[i][1];
                if (next.first < 0 || next.first >= image.size() || next.second < 0 || next.second >= image[0].size() || isVisited[next.first][next.second] || image[next.first][next.second] != srColor)                         continue;
                q.push(next);
            }
        }
        return image;
    }
};
```

#### [542. 01 矩阵](https://leetcode-cn.com/problems/01-matrix/)

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1: 
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2: 
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。





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

