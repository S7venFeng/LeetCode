class Solution {
        public:
        int minNumberOperations(vector<int>& target) {
            int n = target.size();
            vector<int> f(n);
            f[0] = target[0];
            for (int i = 1; i < n; ++i) {
                if (target[i] <= target[i - 1]) {
                    f[i] = f[i - 1];
                } else {
                    f[i] = target[i] - target[i - 1] + f[i - 1];
                }
            }
            return f[n - 1];
        }
};