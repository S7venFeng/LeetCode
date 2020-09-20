# 第35场双周赛

**排名：758/ 2839，AC一题，3分**

![image-20200921000042284](C:\Users\S7ven\AppData\Roaming\Typora\typora-user-images\image-20200921000042284.png)

被超时打崩的一场，不过这次的题目比以往要难一些，分值是3/5/5/6，所以导致7分钟一题都能进1000。。

1. #### [5503. 所有奇数长度子数组的和](https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/)

   打卡题，因为数据规模很小，直接暴力就能出结果，就写的时间长了点

```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        // 1.. 3.. 5... 2k + 1
        int ans = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = 0; j + i <= n; ++j) {
                for (int k = j; k < j + i; ++k) {
                    ans += arr[k];
                } 
            }
        }
        return ans;
    }
};
```

#### 2. [5505. 所有排列中的最大和](https://leetcode-cn.com/problems/maximum-sum-obtained-of-any-permutation/)

个人觉得出的非常好的一道题目，看上去都知道求区间和求区间最大值，但是因为数据规模在10的5次方，通过哈希表来保存区间每个数的出现次数是会超时的（外层有个O（n）遍历是O（n），一个区间同时增加我们可以通过差分的形式来优化，这样就不需要再去遍历整个区间了。

Todo：补充实现代码

#### 3. 5504. 使数组和能被 P 整除](https://leetcode-cn.com/problems/make-sum-divisible-by-p/)

又是道被数据规模卡到超时的题目，想到了用前缀和优化，但是没有想到是通过余数来做前缀和，没有想到去结合余数的性质。这道题目也出的很好，可以好好做下。

Todo：补充实现代码

4.[5506. 奇怪的打印机 II](https://leetcode-cn.com/problems/strange-printer-ii/)

还没做，就不总结了，待补充。