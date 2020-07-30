class Solution {
        public:
        bool check(unordered_map<char, int> &m1, unordered_map<char, int> &m2) {
            for (auto x : m1) {
                if (x.second != m2[x.first]) {
                    return false;
                }
            }
            return true;
        }
        bool checkInclusion(string s1, string s2) {
            int n1 = s1.size();
            int n2 = s2.size();
            unordered_map<char, int> m1(n1);
            unordered_map<char, int> m2(n2);
            int mn = min(n1, n2);
            for (auto c : s1) {
                m1[c]++;
            }
            for (int i = 0; i < mn; ++i) {
                m2[s2[i]]++;
            }
            if (true == check(m1, m2)) {
                return true;
            }
            for (int i = mn; i < n2; ++i) {
                m2[s2[i - n1]]--;
                m2[s2[i]]++;
                if (true == check(m1, m2)) {
                    return true;
                }
            }
            return false;
        }
};