class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for (int i = 0; i < trips.size(); ++i) {
            pair<int, int> p = {trips[i][1], trips[i][0]};
            v.push_back(p);
            p = {trips[i][2], -trips[i][0]};
            v.push_back(p);
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        int ans = 0;
        int res = 0;
        for (auto x : v) {
            res += x.second;
            ans = max(ans, res);
        }
        return ans <= capacity;
    }
};