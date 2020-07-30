# SlidingWindow滑动窗口系列题
## 滑动窗口一般用来在某个区域段（窗口）里面求满足条件的子集


## 题目示例：
### 题目一：
### 76. 最小覆盖子串（Hard）
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。


### 思路
此题为滑动窗口的模板题变种题（窗口长度非固定），那么，为什么我们第一时间能想到使用滑动窗口？

首先，根据题意是在S串的所有子串里面去找满足条件：T串里面的每个元素出现次数和S的子串一致（其实是S的子串里面T每个元素出现次数大于T串自己每个元素出现个数），描述有点绕，可以结合代码看下
**也就是我上面所说的check函数**
``` C++
bool check(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
    for (auto x : m2) {
        if (m1[x.first] < x.second) {
            return false;
        }
    }
    return true;
}
```
m1为存储S子串窗口内每个元素出现的次数，m2位存储T子串窗口内每个元素出现的次数，要在字符串 S 里面找出：包含 T 所有字符的最小子串，就是遍历m2每个元素，m1的值大于等于m2该元素出现个数

**以上描述的就符合了滑动窗口的应用场景：在某个区域段（窗口）里面求满足条件的子集。其中，l和r两个指针维护了S子串窗口，当该窗口内的条件check失败时，r++往右移动到直到满足条件，当满足条件时，l++收缩窗口，这么做的原因是为了求窗口最小值
当l++到窗口内check再次失败时，r++再往前走……**

## 解法一（滑动窗口）：
```  C++
class Solution {
        public:
        bool check(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
            for (auto x : m2) {
                if (m1[x.first] < x.second) {
                    return false;
                }
            }
            return true;
        }
        string minWindow(string s, string t) {
            int s1 = s.size();
            int s2 = t.size();
            unordered_map<char, int> m1;
            unordered_map<char, int> m2;
            for (auto c : t) {
                m2[c]++;
            }
            int i = 0, j = 0;
            string ans;
            bool firstFlag = true;
            for (; i < s1; ++i) {
                m1[s[i]]++;
                if (!check(m1, m2)) continue;
                while (j <= i && check(m1, m2)) {
                    if (firstFlag) {
                        ans = s.substr(j, i - j + 1);
                        firstFlag = false;
                    }
                    if (i - j + 1 < ans.size()) {
                        ans = s.substr(j, i - j + 1);
                    }
                    m1[s[j]]--;
                    j++;
                }
            }
            return ans;
        }
};

```
