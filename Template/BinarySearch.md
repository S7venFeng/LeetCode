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

return lower_bound(arr.begin(), arr.end());
return upper_bound(arr.begin(), arr.end());
```

