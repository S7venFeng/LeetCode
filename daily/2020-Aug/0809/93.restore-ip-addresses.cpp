class Solution {
public:
    void dfs(string s, int idx, vector<int> &part, vector<vector<int>> &ans) {
        if (part.size() >= 4 && idx < s.size() - 1) return;
        if (idx >= s.size() && part.size() == 4) {
            ans.push_back(part);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (idx + i < s.size()) {
                string tmp = s.substr(idx, i + 1);
                int num = atoi(tmp.c_str());
                if (num > 255) return;
                part.push_back(num);
                dfs(s, idx + i + 1, part, ans);
                part.pop_back();
            }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        // dfs
        int n = s.size();
        if (n < 4 || n > 12) {
            return vector<string> {};
        }
        vector<int> part;
        vector<vector<int>> ans;
        dfs(s, 0, part, ans);
        vector<string> res;
        for (auto x : ans) {
            string ss;
            for (auto a : x) {
                ss += to_string(a);
                ss += ".";
            }
            ss.pop_back();
            if (ss.size() != s.size() + 3) continue;
            res.push_back(ss);
        }

        return res;
    }
};