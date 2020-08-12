

# 二分查找

## 二分查找算是入门简单，但是总容易写错或者说不知道什么时候要二分的题目，这2个问题解决了，就不再怕二分了。第一个问题熟用模板就可以搞定，第二个问题则是要多练找感觉了，碰到数据规模比较大（10^5）我们要在一个范围内搜寻答案的话，我们就可以考虑用二分试试了

## 首先，先看下模板吧：

二分的模板有很多种，这里我放出来我用的最多的一种，外层while是(l < r)判断，里面mid是(l + r) >> 1或者(r - l) >> 1 + l（防止溢出），然后check(mid)条件满足或者不满足的情况下有两种路径：

1. r = mid，要搜寻的结果在[0, mid]区间内
2. l = mid，要搜寻的结果在[mid, r]区间内，**注意此时的mid要改为mid = (l + r + 1) >> 1****（记住就行了）**

所以，二分的关键就是要找对check函数，让每次我们整个范围的数划分成2个部分，一部分满足条件，一部分不满足条件，看到这里你应该明白了：**要用二分目标数组不一定要具有单调性，但是有单调性的数组必定能使用二分**

```c++
int binarySearch(vector<int> &arr) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
		if (!check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
        /*
        if (!check(mid)) {
        	l = mid;
        } else {
        	r = mid - 1;
        }
        */
    }
    return l;
}
```

**然后就是C++ STL里面常用的两个在有序容器里面搜寻大于或大于等于某个数的第一个数的方法：**

```c++
return binary_search(nums.begin(), nums.end(), target) == false // 判断有序数组里面是否包含target
return lower_bound(arr.begin(), arr.end(), target) - arr.begin(); // 找到第一个大于等于target的索引位置
return upper_bound(arr.begin(), arr.end(), target) - arr.begin(); // 找到第一个大于target的索引位置
```

**下面，通过一些模板题来加深下对模板的运用理解：**



## 模板题：

#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

**此题和153同源**

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

## 思路一（二分模板）：

这道题是在有序数组里面查找元素，很明显是一道二分查找题目，但是这里不是查找某个元素的索引而是查找某个元素的第一次出现和最后一次出现的位置。

知道用模板了，那么我们要找一下模板中的check函数，此处的check函数分别是：

1. nums[mid] >= target，此时我们的答案是在[l, mid]这个区间内，target有可能就是mid，**这样找到的是从l往r方向第一个等于target的位置**
2. nums[mid] <= target，此时我们的答案是在[mid, r]这个区间内，target有可能就是mid，**这样找到的是从r往l方向第一个等于target的位置**

注意，因为我们是要找第一个或最后一个等于target的数，所以一定要加上等于号，让我们的区间往target那个方向上缩

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> ans;
        while (l < r) {
            int mid = ((r - l) >> 1) + l;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l == nums.size() || nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(l);
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = ((r - l + 1) >> 1) + l;
            if (nums[mid] <= target) {
                l = mid;         
            } else {
                r = mid - 1;
            }
        }
        ans.push_back(r);
        return ans;
    }
};
```



## 思路二（STL接口）：

STL接口就比较简单了，直接套用模板就行了，注意下，lower_bound和upper_bound(**返回第一个大于target的数，如果数组里面已经确定有target了，那么就是该迭代器的前一个位置**)返回的都是迭代器的位置，该位置有可能是等于nums.end()的，这个位置是非法的，注意要判断下。这里面因为已经排除了非法位置（找不到的情况）就不需要再判断了

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if (binary_search(nums.begin(), nums.end(), target) == false) {
            return vector<int>{-1, -1};
        }
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return vector<int>{l, r};
    }
};
```

#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

## 思路一（二分查找）：

这题的目标数组是无序的，但是这个数组是有一定的特征：数组被分成了两段，两段分别有序。所以**我们首先要确定要找的数落在哪个有序区间里面，找到后在那个区间再二分查找即可。**那么，如何来找这个区间呢？我们先要找到将这个2个数组分开的一个数，这个数就是我们第一次二分的target点。仔细观察两个有序区间，发现左边区间的所有数都大于数组的最后一个数，右边区间的所有数都小于数组的最后一个数，所以数组的最后一个数就是分离点，那么第一次二分的check函数就有了（nums[mid] <= nums.back())，找到这个分离点后，判断target和这个分离点（最小元素）的关系，就能确定target在哪个区间了，再进行第二次二分查找即可。

**此处nums[mid] <= nums.back()的情况下，让r=mid是因为这个点一定是在[l, mid]这个区间内，同理，当nums[mid] > nums.back()时，分离点一定在(mid, r)位置**

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (!nums.size()) {
            return -1;
        }
        if (target == nums.back()) {
            return n - 1;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= nums.back()) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int minIdx = l;
        if (target <= nums.back()) {
            l = minIdx, r = n - 1;
        }
        else {
            l = 0, r = minIdx - 1;
        }  
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
```

#### [275. H指数 II](https://leetcode-cn.com/problems/h-index-ii/)

给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。

h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"

示例:

输入: citations = [0,1,3,5,6]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。


说明:

如果 h 有多有种可能的值 ，h 指数是其中最大的那个。

## 思路一：

题目有点绕，**意思就是要找到一个h，让这个数组至少有h个数大于等于h，求最大的这个h**

我们依据这个性质，将数组分为两个区间，左边的区间满足这个性质，右边的区间不满足这个性质，然后中间这个h就是我们要的答案。这个性质是：至少有h个数大于等于h。搜索的范围是[0, n]，因为一旦h满足了这个性质，小于等于h的都满足，那就相当于我们要在这个区间里面找寻最大的符合条件的数，结合第34题能想到mid一定是往右边大的区间里面去缩，所以我们的check(mid)的节结果必然是l = mid。让我们来看下check函数怎么找

此处我们要比较的两个数是cit[nums.size() - mid] >= mid，nums.size() - mid代表的是倒数第mid个数，因为要找到h个数大于等于h，那么我们找倒数第h个数看他是否大于h即可，如果大于则满足条件区间缩小，否则区间则往大处缩。

可以反过来想，如果cit[n - mid]这个值要小于mid，则表示没满足条件，r = mid - 1，区间往左边缩。

```c++
class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        if (cit.empty()) return 0;
        int l = 0, r = n;
        while (l < r) {
            int mid = ((long long)l + r + 1) >> 1; 
            if (cit[n - mid] >= mid) { // 倒数第mid个数大于等于mid，满足条件 往满足条件的右边缩
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

## 下面，我们看一些应用题，如何运用二分查找来搜寻答案的

## 应用题：

#### [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

## 思路：

这题直接算能够算出结果，但这里我们使用二分查找来加速一下。

首先，此处x的平方根的结果范围我们可以粗略估计下，应该是[0, x]，答案只会在这个范围，我们用二分来缩小这个范围直到满足结果

此处的check条件就是mid的平方小于等于x，如果满足则l = mid(反过来想，如果mid平方大于x，不满足条件下次搜寻时r = mid - 1)

```c++
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            long long res = mid * mid;
            if (res <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### [875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/)

珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

示例 1：

输入: piles = [3,6,7,11], H = 8
输出: 4
示例 2：

输入: piles = [30,11,23,4,20], H = 5
输出: 30
示例 3：

输入: piles = [30,11,23,4,20], H = 6
输出: 23

**提示：**

- `1 <= piles.length <= 10^4`
- `piles.length <= H <= 10^9`
- `1 <= piles[i] <= 10^9`

## 思路：

非常经典的一道题目，每次想到二分查找的应用题我首先想到的都是它（主要用例3 还是4数据就上了千万，猩猩这么能吃我是没想到的……）

题意是比较简单的，让我们找一个最小速度K，满足在H小时能吃完香蕉，耗费时间的方程我们是很容易想到的。关键就是我们怎么快速得出这个“最小”速度

首先，我们先看下答案的范围，答案最高一定不超过max[piles]，为啥呢？因为如果速度是数组的最大值的话，每个香蕉我都能1个小时吃掉, 最小值呢可以去计算，此处我们就选1作为最小值好了（懒得算了）

**然后我们去[1,MAX]这个区间来二分答案，当满足小于等于H时间的情况下时，我们将搜索范围往左缩（取最小值）即可，最后的结果就是满足题意的最小答案**

```c++
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            long long mid = (r + l) >> 1;
            int cnt = 0;
            for (auto x : piles) {
                if (x <= mid) {  // 不足k的堆数一次吃完
                    cnt++;
                } else if (x % mid == 0){ 
                    cnt += x / mid;
                } else {
                    cnt += x / mid + 1;
                }
            }
            if (cnt <= H) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

1011

1482