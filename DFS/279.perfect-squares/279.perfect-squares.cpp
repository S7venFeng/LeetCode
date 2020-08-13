class Solution {
public:
    int dfs(vector<int> &nums, int n, vector<int> &mo) {
        if (n == 0) return 0;
        if (mo[n]) {
            return mo[n];
        }
        int mn = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (n - nums[i] < 0) continue;
            mn = min(mn, 1 + dfs(nums, n - nums[i], mo));
        }
        mo[n] = mn;
        return mn;
    }

    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; (i * i) <= n; ++i) {
            nums.push_back(i * i);
        }
        vector<int> mo(n + 1);
        return dfs(nums, n, mo);
    }
};