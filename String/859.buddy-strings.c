class Solution {
        public:
        bool buddyStrings(string A, string B) {
            int n1 = A.size();
            int n2 = B.size();
            if (!n1 && !n2) return false;
            if (n1 != n2) return false;
            unordered_map<char, int> a;
            unordered_map<char, int> b;
            for (int i = 0; i < n1; ++i) {
                a[A[i]]++;
                b[B[i]]++;
            }
            auto x = a.begin();
            while (x != a.end()) {
                if (x->second != b[x->first]) return false;
                x++;
            }
            int cnt = 0;
            for (int i = 0; i < n1; ++i) {
                if (A[i] != B[i]) {
                    cnt++;
                    if (cnt > 2) return false;
                }
            }
            if (A != B) return true;
            bool flag = false;
            for (int i = 0; i < n1; ++i) {
                if (a[A[i]] > 1) return true;
            }
            return false;
        }
};