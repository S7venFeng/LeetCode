class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ive) {
        sort(ive.begin(), ive.end());
        vector<int> begin(2);
        vector<vector<int>> ans;
        begin[0] = -0x3f3f3f3f;
        begin[1] = -0x3f3f3f3f;
        int st = begin[0];
        int end = begin[1];
        for (auto x : ive) {
            if (end < x[0]) {
                if (st != -0x3f3f3f3f) {
                    vector<int> tmp(2);
                    tmp[0] = st;
                    tmp[1] = end;
                    ans.push_back(tmp);
                }
                st = x[0];
                end = x[1];

            } else {
                end = max(x[1], end);
            }
        }
        if (st != -0x3f3f3f3f) {
            vector<int> tmp(2);
            tmp[0] = st;
            tmp[1] = end;
            ans.push_back(tmp);
        }
        return ans;
    }
};