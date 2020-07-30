class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int getIndex(int x, int y, int m) {
        return x * m + y;
    }
    int find(vector<int> &p, int x)
    {
        while (p[x] != x) {
            x = find(p, p[x]);
        }
        return p[x];
    }
    void merge(vector<int> &p, int a, int b) {
        if (find(p, a) != find(p, b)) {
            p[find(p, a)] = find(p, b);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        if (!board.size()) return;
        int n = board.size();
        int m = board[0].size();
        vector<int> p(n * m + 1);
        int dummyNode = n * m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[getIndex(i, j, m)] = getIndex(i, j, m);
            }
        }
        p[dummyNode] = n * m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        int idx = getIndex(i, j, m);
                        merge(p, idx, dummyNode);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int curX = i + dir[k][0];
                            int curY = j + dir[k][1];
                            if (curX < 0 || curX >= n || curY < 0 || curY >= m) continue;
                            if (board[curX][curY] == board[i][j]) {
                                int nextIdx = getIndex(curX, curY, m);
                                int nowIdx = getIndex(i, j, m);
                                merge(p, nextIdx, nowIdx);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = getIndex(i, j, m);
                if (find(p, idx) == find(p, dummyNode)) {
                    continue;
                }
                board[i][j] = 'X';
            }
        }
        return;
    }
};