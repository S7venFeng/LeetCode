class Solution {
        public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            long long ans = 0;
            int num = 1e9 + 7;
            vector<int> sum(n + 1);
            sum[0] = 0;
            int odd = 0;
            int ies = 0;
            for (int i = 1; i <= n; ++i) {
                sum[i] = sum[i - 1] + arr[i - 1];
                if (sum[i] & 1) {
                    odd++;
                } else {
                    ies++;
                }
            }
            int oddNow = 0;
            int iesNow = 0;
            for (int i = 1; i <= n; ++i) {
                if (sum[i] & 1) {
                    oddNow++;
                    ans += 1;
                    ans += n - iesNow - odd;
                } else {
                    iesNow++;
                    ans += n - ies - oddNow;
                }
            }
            ans = ans % num;
            return ans ;
        }
};