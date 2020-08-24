class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        string s = to_string(n);
        int m = s.size();
        int cnt = 0;
        for (int i = m - 1; i >= 0; --i) {
            cnt++;
            if (cnt == 3 && i != 0) {
                cnt = 0;
                ans += s[i];
                ans += ".";
                continue;
            }
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};