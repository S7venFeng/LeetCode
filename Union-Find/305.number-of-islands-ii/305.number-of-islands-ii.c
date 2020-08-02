class Solution {
        public:
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int getNode(int x, int y, int n) {
            return x * n + y;
        }

        int find(vector<int> &p, int x) {
            while (p[x] != x) {
                x = find(p, p[x]);
            }
            return p[x];
        }

        vector<int> numIslands2(int m, int n, vector<vector<int>>& pos) {
            vector<int> p(m * n);
            vector<int> matr(m * n);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    p[getNode(i, j, n)] = getNode(i, j, n);
                    matr[getNode(i, j, n)] = 0;
                }
            }
            vector<int> ans;
            int cnt = 0;
            for (int i = 0; i < pos.size(); ++i) {
                int curX = pos[i][0];
                int curY = pos[i][1];
                if (matr[getNode(curX, curY, n)]) {
                    ans.push_back(cnt);
                    continue;
                }
                matr[getNode(curX, curY, n)] = 1;
                cnt++;
                for (int j = 0; j < 4; ++j) {
                    int newX = curX + dir[j][0];
                    int newY = curY + dir[j][1];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || !matr[getNode(newX, newY, n)]) continue;
                    int newPos = getNode(newX, newY, n);
                    if (find(p, getNode(curX, curY, n)) != find(p, newPos)) {
                        p[find(p, getNode(curX, curY, n))] = find(p, newPos);
                        --cnt;
                    }
                }
                ans.push_back(cnt);
            }
            return ans;
        }
};