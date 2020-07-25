class Solution {
        public:
        int numSplits(string s) {
            int n = s.size();
            vector<int> left(n + 1);
            left[0] = 0;
            vector<int> right(n + 1);
            right[0] = 0;
            set<char> setL;
            set<char> setR;
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                if (!setL.count(s[i - 1])) {
                    setL.insert(s[i - 1]);
                    left[i] = left[i - 1] + 1;
                } else {
                    left[i] = left[i - 1];
                }
            }
            for (int j = 1; j <= n; ++j) {
                if (!setR.count(s[n - j])) {
                    setR.insert(s[n - j]);
                    right[j] = right[j - 1] + 1;
                } else {
                    right[j] = right[j - 1];
                }
            }
            for (int i = 1; i < n; ++i) {
                int j = n - i;
                if (left[i] == right[j]) {
                    ans += 1;
                }
            }
            return ans;
        }
};