## 前缀和

```c++
vector<int> sum(n);
sum[0] = 0;
for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i - 1];
}
// 求[l,r]区间的和
return s[r] - s[l - 1];
```

## 差分

求一段区间里面加上或者减去一个数

```c++

b[0] + b[1] + ... b[i] = sum[i];
b[0] + b[1] + ... b[i - 1] = sum[i - 1];
b[i] = sum[i] - sum[i - 1];
// 求[l,r]区间各加上一个数c的结果
b[l] += c;
b[r + 1] -= c;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
   		sum[i] += b[j];
    }
}
```





