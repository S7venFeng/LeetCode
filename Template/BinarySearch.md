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

return binary_search(nums.begin(), nums.end(), target) == false // 判断有序数组里面是否包含target
return lower_bound(arr.begin(), arr.end(), target) - arr.begin(); // 找到第一个大于等于target的索引位置
return upper_bound(arr.begin(), arr.end(), target) - arr.begin(); // 找到第一个大于target的索引位置
```

