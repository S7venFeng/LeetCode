class Solution {
        public:
        bool check(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
            for (auto x : m2) {
                if (m1[x.first] != x.second) return false;
            }
            return true;
        }
        vector<int> findAnagrams(string s, string p) {
            int n1 = s.size();
            int n2 = p.size();
            unordered_map<char, int> m1, m2;
            if (n2 > n1) return vector<int>{};
            for (auto a : p) {
                m2[a]++;
            }
            int i = 0, j = 0;
            vector<int> ans;
            while (i < n1) {
                while (i - j + 1 < n2) {
                    m1[s[i]]++;
                    ++i;
                }
                m1[s[i]]++;
                while (i - j + 1 > n2) {
                    m1[s[j]]--;
                    j++;
                }
                if (check(m1, m2)) {
                    ans.push_back(j);
                }
                ++i;
            }
            return ans;
        }
};