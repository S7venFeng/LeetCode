# 并查集
## 并查集是一种基于树结构的一种基本数据结构，**常用来解决两个场景的问题：1、将两个集合合并 2、求两个节点是否属于一个集合
## 当符合以上2个场景的题目出现，我们就可以考虑并查集
## 并查集与DFS\BFS等搜索手段通常一起出现

### 模板：
```C++
vector<int> p(n);
int find(int x) {
    while (p[x] != x) {
        x = find(p[x]);
    }
    return p[x];
}
void merge(int a, int b) {
    if (find(a) != find(b)) {
        p[find(a)] = find(b);
    }
    return;
}
```
**并查集的模板非常简单，代码也很简洁，一般用一个一维数组来保存每个节点的父节点，而每个节点的父亲都是该树的root节点，所以判断两个节点是否在同一个集合，只要判断p[a]==p[b]是否成立即可
由此，诞生两个经典方法，find和union(merge)，find函数就是求某个节点的父节点（根节点），注意此处是递归查找，在递归查找的同时把每个父亲节点同时指向根节点，这是路径压缩的优化，非常优美也非常重要
union操作就是将两个节点所属的集合做合并，先判断两个节点父节点是否相同，相同表明已经是一个集合内了，如果不相同，将其中一个的父节点的父亲节点指向另外一个节点的父节点即可（两个任选一个都行）**

当完成模板后，我们看几道经典的模板题目来加深下理解。

### 题目一：Leetcode-547.朋友圈（Mid）
题目描述:
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：

N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。

### 这个题目是我非常喜欢的一道题目，因为他能够当做DFS/BFS/并查集三个提醒的模板题而且也简单易懂，但是你如果没接触过以上三种算法，你会无从下手
## 思路
** 当两个学生是朋友时，我们认为这两个学生属于同一个集合，将两个学生节点做合并操作，合并的同时将cycle数（朋友圈数，开始时我们设置为学生人数，当有两个学生合并，该值减一）减一，遍历整个二维数组做一遍合并该题目就结束了 **
```C++
const int N = 200;
class Solution {
        public:
        vector<int> p;
        int find(int x) {
            while (p[x] != x) {
                x = find(p[x]);
            }
            return p[x];
        }
        int findCircleNum(vector<vector<int>>& M) {
            int n = M.size();
            int ans = n;
            p.resize(n);
            for (int i = 0; i < n; ++i) {
                p[i] = i;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && M[i][j]) {
                        if (find(i) != find(j)) {
                            p[find(i)] = find(j);
                            ans--;
                        }
                    }
                }
            }
            return ans;
        }
};
```

### 题目二：Leetcode-130. 被围绕的区域（Mid）
题目描述:
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

### 又是一道DFS/BFS/并查集都能应用的模板题，不过此题的解题思路需要转个弯思考下，此处先讲并查集解法，后续有时间补充DFS/BFS算法解题思路。
### 思路：
此处我们要找被'X'围绕的O区域，从图中可以看出，被围绕的O区域其实就是不挨边（没有‘O’节点在四个边界上）的联通区域。首先，我们遍历整个二维数组，将其中的'O'节点剥离出来，判断其是否是边界节点，如果是边界节点，则将其与一个
用不到的dummyNode连接，也就是将边界'O'节点全部指向（或者被指向）一个无用节点，这个操作没理解没关系，看到后面你就明白了；如果这个节点不是边界节点，那么我们就以本节点为起点，遍历四个方向的合法节点（不超出边界），将四个方向
的合法节点与本节点做union合并操作，这样我们遍历结束后就会得到两种并查集集合，一种是与dummyNode相连的集合，另外一种是与不与dummyNode相连的集合（可能有多个）。最后我们再次遍历整个图，将不与dummyNode同属一个集合的'O'改为'X'即可
**dummyNode节点的索引和值我们可以让它指向一个不会用到的数，比如n*m(一共只有0至n*m-1这么n*m个数，n*m不包括）**
**union连接操作，谁连向谁都没有关系**

```C++
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int getIndex(int x, int y, int m) {
        return x * m + y;
    }
    int find(vector<int> &p, int x)
    {
        while (p[x] != x) {
            x = find(p, p[x]);
        }
        return p[x];
    }
    void merge(vector<int> &p, int a, int b) {
        if (find(p, a) != find(p, b)) {
            p[find(p, a)] = find(p, b);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        if (!board.size()) return;
        int n = board.size();
        int m = board[0].size();
        vector<int> p(n * m + 1);
        int dummyNode = n * m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[getIndex(i, j, m)] = getIndex(i, j, m);
            }
        }
        p[dummyNode] = n * m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        int idx = getIndex(i, j, m);
                        merge(p, idx, dummyNode);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int curX = i + dir[k][0];
                            int curY = j + dir[k][1];
                            if (curX < 0 || curX >= n || curY < 0 || curY >= m) continue;
                            if (board[curX][curY] == board[i][j]) {
                                int nextIdx = getIndex(curX, curY, m);
                                int nowIdx = getIndex(i, j, m);
                                merge(p, nextIdx, nowIdx);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = getIndex(i, j, m);
                if (find(p, idx) == find(p, dummyNode)) {
                    continue;
                }
                board[i][j] = 'X';
            }
        }
        return;
    }
};
```
