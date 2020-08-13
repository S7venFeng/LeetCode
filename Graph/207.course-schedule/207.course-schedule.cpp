class Solution {
public:
    bool DFS(vector<vector<int>> &g, vector<int> &status, int now) {
        if (status[now] == 1) {
            return true;
        }
        if (status[now] == 2) {
            return false;
        }
        status[now] = 1;
        for (auto a : g[now]) {
            if (status[a] == 1) {
                return true;
            }
            DFS(g, status, a);
        }
        status[now] = 2;
        return false;
    }
    bool canFinish(int nums, vector<vector<int>>& pre) {
        vector<vector<int>> g(nums);
        for (int i = 0; i < pre.size(); ++i) {
            int cur = pre[i][0];
            int next = pre[i][1];
            g[cur].push_back(next);
        }
        // 0-unknown, 1-visiting, 2- visited
        vector<int> status(nums);
        for (int i = 0; i < nums; ++i) {
            if (DFS(g, status, i)) {
                return false;
            }
        }
        return true;
    }
};