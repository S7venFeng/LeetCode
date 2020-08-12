class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (!nums.size()) {
            return -1;
        }
        if (target == nums.back()) {
            return n - 1;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= nums.back()) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int minIdx = l;
        if (target <= nums.back()) {
            l = minIdx, r = n - 1;
        }
        else {
            l = 0, r = minIdx - 1;
        }
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};