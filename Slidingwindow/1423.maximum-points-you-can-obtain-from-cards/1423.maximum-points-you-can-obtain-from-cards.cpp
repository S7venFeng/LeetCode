class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int i = 0, j = k;
        int cnt = 0;
        int ans = 0;
        vector<int> sum(n);
        sum[0] = cards[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + cards[i];
        }
        if (k >= n) {
            return sum[n - 1];
        }
        while (i <= k && j >= 0) {
            if (i == 0) {
                ans = max(ans, sum[n - 1] - sum[n - j - 1]);
            }
            else if (j == k) {
                ans = max(ans, sum[i - 1]);
            }
            else {
                ans = max(ans, sum[i - 1] + sum[n - 1] - sum[n - j - 1]);
            }
            ++i;
            --j;
        }
        return ans;
    }
};