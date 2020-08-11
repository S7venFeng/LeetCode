## 排序

1. 快速排序

   ```c++
   void quick_sort(vector<int> &v, int l, int r) 
   {
       if (l >= r) return;
       int x = v[(l + r) >> 1];
       int i = l - 1, j = r + 1;
       while (i < j) {
           ++i;
           while (v[i] < x) ++i;
           --j;
           while (v[j] > x) --j;
           if (i < j) {
               swap(v[i], v[j]);
           }
       }
       quick_sort(v, l, j);
       quick_sort(v, j + 1, r);
       return;
   }
   ```


2. 快速选择

   ```c++
   // 找到第k小的数
   int quick_sort(vector<int> &v, int l, int r, int k) 
   {
       if (l >= r) return v[l];
       int x = v[(l + r) >> 1];
       int i = l - 1, j = r + 1;
       while (i < j) {
           ++i;
           while (v[i] < x) ++i;
           --j;
           while (v[j] > x) --j;
           if (i < j) {
               swap(v[i], v[j]);
           }
       }
       if (j - l + 1 >= k) {
       	return quick_sort(v, l, j, k);    
       }
       else {
       	return quick_sort(v, j + 1, r, k - (j - l + 1));
       }
   }
   ```

   

3. 归并排序

```c++
void merge_sort(vector<int> &v, int l, int r) 
{
	if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int k = 0;
    vector<int> tmp(r - l + 1);
    while (i <= mid && j <= r) {
        if (v[i] < v[j]) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while (i <= mid) tmp[k++] = v[i++];
    while (j <= r) tmp[k++] = v[j++];
    for (int i = l, j = 0; i <= r; ++i) {
        v[i] = tmp[j++];
    }
    return;
}
```




1. 自定义vector排序

   ```c++
   vector<int> v;
   sort(v.begin(), v.end(), [](const int &a, const int &b){
       return a < b;
   });
   ```

2. 自定义map排序

   ```c++
   unorderd_map<int, int> m;
   sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
       if (a.first == b.first) {
           return a.second < b.second;
       }
       return a.first < b.first;
   });
   ```

   