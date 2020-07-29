class Solution {
        public:
        int maxSatisfied(vector<int>& cu, vector<int>& gru, int X) {
            int n = cu.size();
            int sum = 0;
            int tot = 0;
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (gru[i]) continue;
                sum += cu[i];
            }
            cout << sum;
            for (int i = 0; i < X; ++i) {
                if (gru[i]) sum += cu[i];
            }
            ans = max(ans, sum);
            for (int i = X; i < n; ++i) {
                if (gru[i]) {
                    sum += cu[i];
                }
                if (gru[i - X]) {
                    sum -= cu[i - X];
                }
                ans = max(ans, sum);
            }
            return ans;
        }
};