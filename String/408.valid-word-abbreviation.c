class Solution {
        public:
        bool validWordAbbreviation(string word, string abbr) {
            int n = word.size();
            int m = abbr.size();
            if (!n && !m) return true;
            if (!m) return false;
            int cnt = 0;
            int i = 0;
            int pos = 0;
            for (; i < m; ++i) {
                if (isdigit(abbr[i])) {
                    if (cnt == 0 && abbr[i] == '0') return false;
                    cnt = cnt * 10 + abbr[i] - '0';
                } else {
                    pos += cnt + 1;
                    cnt = 0;
                    if (pos > n || abbr[i] != word[pos - 1]) return false;
                }
            }
            return pos + cnt == n;
        }
};