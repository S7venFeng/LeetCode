class Solution {
public:
    int helper(int x) {
        int res = 0;
        while (x) {
            res++;
            x -= x & (-x);
        }
        return res;
    }

    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32);
        int ans = 0;
        for (int i = 0; i <= 31; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                cnt[i] += (nums[j] >> i) & 1;
            }
            if (cnt[i] % 3) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};