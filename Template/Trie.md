## 字典树

```c++
const int N = 100010;
int son[N][26];
int cnt[N];
int idx = 0;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
        int u = s[i] - 'a';
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

bool find(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
        int u = s[i] - 'a';
        if (!son[p][u]) {
            return false;
        }
        p = son[p][u];
    }
    if (cnt[p]) return true;
}
```

