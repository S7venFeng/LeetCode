class Solution {
        public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            int ans = 0;
            unordered_map<char, int> m;
            int i = 0, j = 0;
            for (; i < n; ++i) {
                m[s[i]]++;
                while (j < i && m[s[i]] > 1) {
                    m[s[j]]--;
                    ++j;
                }
                ans = max(ans, i - j + 1);
            }
            return ans;
        }
};