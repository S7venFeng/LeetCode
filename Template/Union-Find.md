## 并查集

```c++
const int N = 100010;
int p[N];
int cnt[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(x);
    }
    return p[x];
}

void merget(int a, int b) {
    if (find(a) != find(b)) {
        cnt[find(b)] += cnt[find(a)];
        p[find(a)] = find(b);
    }
}

void init() {
    for (int i = 0; i < N; ++i) {
        p[i] = i;
        cnt[i] = 1;
    }
}
```

