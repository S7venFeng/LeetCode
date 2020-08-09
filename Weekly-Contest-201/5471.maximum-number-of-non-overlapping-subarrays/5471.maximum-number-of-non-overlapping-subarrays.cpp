class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        set<int> s;
        s.insert(0);
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int want = sum - target;
            if (s.find(want) != s.end()) {
                ans++;
                s.clear();
                sum = 0;
            }
            s.insert(sum);
        }
        return ans;
    }
};