# 前缀和 & 差分







## 当需要我们将一个区间同时加或者减一个数时，我们常常会用到差分算法。

### 其实差分概念很简单，差分就是前缀和的逆运算，每个差分的数从0-n相加就是前缀和结果s[n]

### 差分数b[i] = a[i] - a[i - 1]

### 当我们让[l，r]这个区间每个数都加上c时，我们只需要将b[l] += c, b[r + 1] -= c，这样[l, r]这个区间的每个a[i]都加上了c

### 结果不难验证，a[l] = a[l - 1] + b[l]，因为b[l] += c，所以a[i]也加了c，那么a[i+1] = a[i] + b[i + 1]也相当于加了c；a[r + 1]  = a[r] + b[r + 1]，注意此时的a[r] 是加过c的，我们要让a[r+1]和原来一样则必须让b[r + 1] -= c，所以这么计算就是正确的

结合例子看就非常清楚了~

#### [370. 区间加法](https://leetcode-cn.com/problems/range-addition/)

假设你有一个长度为 n 的数组，初始情况下所有的数字均为 0，你将会被给出 k 个更新的操作。

其中，每个操作会被表示为一个三元组：[startIndex, endIndex, inc]，你需要将子数组 A[startIndex ... endIndex]（包括 startIndex 和 endIndex）增加 inc。

请你返回 k 次操作后的数组。

示例:

输入: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
输出: [-2,0,3,5,3]
解释:

初始状态:
[0,0,0,0,0]

进行了操作 [1,3,2] 后的状态:
[0,2,2,2,0]

进行了操作 [2,4,3] 后的状态:
[0,2,5,5,3]

进行了操作 [0,2,-2] 后的状态:
[-2,0,3,5,3]

```c++
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = length;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] = a[i] - a[i - 1];
        }
        for (int i = 0; i < updates.size(); ++i) {
            b[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < n) {
                b[updates[i][1] + 1] -= updates[i][2];
            }   
            a[0] = b[0];           
        }
        for (int j = 1; j < n; ++j) {
                a[j] = a[j - 1] + b[j];
        }
        return a;
    }
};
```

