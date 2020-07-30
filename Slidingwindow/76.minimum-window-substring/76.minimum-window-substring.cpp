class Solution {
        public:
        bool check(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
            for (auto x : m2) {
                if (m1[x.first] < x.second) {
                    return false;
                }
            }
            return true;
        }
        string minWindow(string s, string t) {
            int s1 = s.size();
            int s2 = t.size();
            unordered_map<char, int> m1;
            unordered_map<char, int> m2;
            for (auto c : t) {
                m2[c]++;
            }
            int i = 0, j = 0;
            string ans;
            bool firstFlag = true;
            for (; i < s1; ++i) {
                m1[s[i]]++;
                if (!check(m1, m2)) continue;
                while (j <= i && check(m1, m2)) {
                    if (firstFlag) {
                        ans = s.substr(j, i - j + 1);
                        firstFlag = false;
                    }
                    if (i - j + 1 < ans.size()) {
                        ans = s.substr(j, i - j + 1);
                    }
                    m1[s[j]]--;
                    j++;
                }
            }
            return ans;
        }
};