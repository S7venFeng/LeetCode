class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> ans;
        while (l < r) {
            int mid = ((r - l) >> 1) + l;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l == nums.size() || nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(l);
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = ((r - l + 1) >> 1) + l;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans.push_back(r);
        return ans;
    }
};