class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int r = 0;
        int l = 0;
        vector<int> ans;
        for (auto a : weights) {
            r += a;
            l = max(a, l);
        }
        int mx = r;
        while (l <= r) {
            int mid = ((r - l) >> 1) + l;
            int cnt = 0;
            int days = 0;
            for (int i = 0; i < weights.size(); ++i) {
                cnt += weights[i];
                if (cnt == mid) {
                    days++;
                    cnt = 0;
                } else if (cnt > mid) {
                    days++;
                    cnt = weights[i];
                }
            }
            if (cnt < mid) {
                days++;
            }
            if (days > D) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans.push_back(mid);
            }
        }
        if (l == mx + 1) {
            return mx;
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};