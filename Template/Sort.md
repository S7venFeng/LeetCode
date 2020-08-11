## 排序

1. 快速排序

2. 归并排序

3. 自定义vector排序

   ```c++
   vector<int> v;
   sort(v.begin(), v.end(), [](const int &a, const int &b){
       return a < b;
   });
   ```

4. 自定义map排序

   ```c++
   unorderd_map<int, int> m;
   sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
       if (a.first == b.first) {
           return a.second < b.second;
       }
       return a.first < b.first;
   });
   ```

   