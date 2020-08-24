class Solution {
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

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        init();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (find(i * m + j) == find((i - 1) * m + j)) {
                        return true;
                    } else {
                        p[find(i * m + j)] = find((i - 1) * m + j);
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (find(i * m + j) == find(i * m + j - 1)) {
                        return true;
                    } else {
                        p[find(i * m + j)] = find(i * m + j - 1);
                    }
                }
            }
        }
        return false;
    }
};