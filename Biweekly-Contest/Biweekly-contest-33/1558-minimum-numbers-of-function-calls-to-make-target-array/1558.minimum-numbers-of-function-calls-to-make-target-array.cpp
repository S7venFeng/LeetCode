class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        while(true) {
            bool flag = false;
            bool modify = false;
            for (int i = 0; i < n; ++i) {
                if (nums[i] % 2 != 0) {
                    nums[i]--;
                    ans++;
                    modify = true;
                }
                if (nums[i]) {
                    nums[i] = nums[i] / 2;
                    modify = true;
                    flag = true;
                }
            }
            if (!modify) return ans;
            if (flag) {
                ans++;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int ones = 0;
            int bits = 0;
            while (x) {
                if (x & 1) ones++;
                x >>= 1;
                bits++;
            }
            ans += ones;
            k = max(k, bits);
        }
        return k - 1 + ans;
    }
};