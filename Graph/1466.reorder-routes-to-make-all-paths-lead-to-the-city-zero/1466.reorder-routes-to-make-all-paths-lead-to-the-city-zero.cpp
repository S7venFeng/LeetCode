class Solution {
public:
    int DFS(vector<vector<pair<int,int>>> &vec, int &now, int &father) {
        int res = 0;
        for (auto &e : vec[now]) {
            if (e.first == father) continue;
            res += DFS(vec, e.first, now) + e.second;
        }
        return res;
    }

    int minReorder(int n, vector<vector<int>>& cs) {
        vector<vector<pair<int,int>>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].clear();
        }
        for (auto &e : cs) {
            int src = e[0];
            int dst = e[1];
            vec[src].push_back({dst, 1});
            vec[dst].push_back({src, 0});
        }
        int now = 0;
        int father = -1;
        int res = 0;
        res = DFS(vec, now, father);
        return res;
    }
};