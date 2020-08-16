# 第202场周赛

又是打的很差的一场，前两道题十分钟AC后，后面2道就没再写出来。排名又是1000名开外

!(https://github.com/S7venFeng/LeetCode/blob/master/Weekly-Contest/Weekly-Contest-202/Weekly-Contest-202.png)

总结下四道题目吧：

1. #### [5185. 存在连续三个奇数的数组](https://leetcode-cn.com/problems/three-consecutive-odds/)

   打卡题，没什么特别要注意的，遍历一遍直接输出结果就行了

2. #### [5488. 使数组中所有元素相等的最小操作数](https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/)

   挺有意思的一道题目，比较容易看出来规律，看出规律后题目就比较简单了

3. #### [5489. 两球之间的磁力](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/)

   个人觉得出的最好的一道题，有区分度，上来感觉是二分，但是二分的内容和check函数一直想错了，原本想着二分每个位置，其实是二分整个答案。不过有一点学到了就是：**最大值最小化、最小值最大化一般来说都是二分题目。因为结果一定是最小化或者最大化的，左边的是满足这个结果的但是比结果要更大或者更小，右边是不满足结果的，所以相当于结果把区间分成了两部分，一部分满足一部分不满足，这就是二分常用的性质。**

4. #### [5490. 吃掉 N 个橘子的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges/)

   第一眼看上去觉得是一道白给的DP题，但想想作为困难题又太简单了些，果然写完开始各种超时。因为从头到尾想的就是DP，也没想到用DFS/BFS记忆化来解决，所以这题也没了

比赛结果很差，发现自己还是对典型的一些题目掌握的不够，继续加油吧。