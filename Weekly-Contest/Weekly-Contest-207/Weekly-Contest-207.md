# 第207场周赛

**排名：462/ 4115，AC三题，12分**

![image-20200920234020952](C:\Users\S7ven\AppData\Roaming\Typora\typora-user-images\image-20200920234020952.png)

最近打的最好的一场周赛，看看四道题目:

1. #### [5519. 重新排列单词间的空格](https://leetcode-cn.com/problems/rearrange-spaces-between-words/)

   打卡题，基本是直接模拟就能出来的题目，写了7分钟的原因是有两次低级的bug解决了较长时间，总体还行

2. #### [5520. 拆分字符串使唯一子字符串的数目最大](https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

   数据规模是16，第一眼看上去就感觉要用dfs来爆搜，但是这道题写加调试花了接近一个小时，非常差，原因就是dfs遍历时候进入跟退出的边界写的很模糊，不断通过尝试才最终确定，这点一定需要加强，可以看看题解如何写的简单点。

3. #### [5521. 矩阵的最大非负积](https://leetcode-cn.com/problems/maximum-non-negative-product-in-a-matrix/)

   题目很明显是一道DP题，没什么大的问题，但是出现了三次提交错误，这个是非常不应该的。第一次是手抖不小心点到提交了没办法。。后面基本都是大数据处理的问题，LL格式的数据取模一直写的有问题，一般都会错个1-2次，就是中间一些数据没有使用LL保存导致。个人觉得这题出的比较一般，没有什么特色，不过可以看看题解有没有更好的方法。

4. #### [5522. 连通两组点的最小成本](https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points/)

有进步的一场周赛，下次继续加油