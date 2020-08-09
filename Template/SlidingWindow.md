```c++
int i = 0;
int j = i + 1;
for (int i = 0, j = 0; i < n; ++i) {
    while (j < i && check(i, j)) {
        ans = max(ans, j - i + 1);
        ++j;
    }
}
```

