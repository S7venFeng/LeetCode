class Solution {
        public:
        bool isLongPressedName(string name, string typed) {
            int n = name.size();
            int m = typed.size();
            if (n > m) return false;
            int i = 0, j = 0;
            for (; i < n && j < m; ) {
                if (name[i] == typed[j]) {
                    ++i;
                    ++j;
                } else {
                    while (j > 0 && typed[j] == typed[j - 1]) {
                        j++;
                    }
                    if (name[i] != typed[j]) return false;
                }
            }
            if (i < n) return false;
            if (j < m) {
                while (j > 0 && typed[j] == typed[j - 1]) {
                    j++;
                }
                if (j < m) return false;
            }
            return true;
        }
};