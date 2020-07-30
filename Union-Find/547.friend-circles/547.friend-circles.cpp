const int N = 200;
class Solution {
        public:
        vector<int> p;
        int find(int x) {
            while (p[x] != x) {
                x = find(p[x]);
            }
            return p[x];
        }
        int findCircleNum(vector<vector<int>>& M) {
            int n = M.size();
            int ans = n;
            p.resize(n);
            for (int i = 0; i < n; ++i) {
                p[i] = i;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && M[i][j]) {
                        if (find(i) != find(j)) {
                            p[find(i)] = find(j);
                            ans--;
                        }
                    }
                }
            }
            return ans;
        }
};