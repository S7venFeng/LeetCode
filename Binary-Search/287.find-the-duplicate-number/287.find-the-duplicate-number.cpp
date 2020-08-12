class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (long long)(l + r) >> 1;
            int cnt = 0;
            for (auto x : nums) {
                if (x >= l && x <= mid) {
                    cnt++;
                }
            }
            if (cnt > mid - l + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};