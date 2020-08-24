## 并查集

```c++
private:
static const int N = 250100;
public:
    int p[N];
    int cnt[N];

    int find(int x) {
        if (p[x] != x) {
            x = find(p[x]);
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

