class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<bool> f(target + 1);
        for (int i = 1; i < n; ++i) {
            for (int j = target; j >= 0; --j) {
                if (j == nums[i]) {
                    f[j] = true;
                    continue;
                }
                if (j > nums[i]) {
                    f[j] = f[j] || f[j - nums[i]];
                }
            }
        }
        return f[target];
    }
};