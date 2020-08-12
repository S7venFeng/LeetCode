class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        if (cit.empty()) return 0;
        int l = 0, r = n;
        while (l < r) {
            int mid = ((long long)l + r + 1) >> 1;
            if (cit[n - mid] >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};