## 堆 & 优先级队列

1. 优先级队列

   ```c++
   // 默认大顶堆
   priority_queue<int, vector<int>, less<int>> pq;
   // 小顶堆
   priority_queue<int, vector<int>, greater<int>> pq;
   pq.push();
   pq.pop();
   // 补充自定义排序
   ```

   