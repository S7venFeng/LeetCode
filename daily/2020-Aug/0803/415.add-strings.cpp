class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        int mx = max(m, n);
        string ans;
        ans.resize(mx + 1);
        int carry = 0;
        int i = m - 1, j = n - 1;
        int idx = mx - 1;
        for (; i >= 0 && j >= 0; --i, --j) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = sum >= 10 ? sum / 10 : 0;
            ans[idx--] = sum % 10 + '0';
        }
        if (i >= 0) {
            for (int k = i; k >= 0; --k) {
                int sum = num1[k] - '0' + carry;
                carry = sum >= 10 ? sum / 10 : 0;
                ans[k] = sum % 10 + '0';
            }
        }
        if (j >= 0) {
            for (int k = j; k >= 0; --k) {
                int sum = num2[k] - '0' + carry;
                carry = sum >= 10 ? sum / 10 : 0;
                ans[k] = sum % 10 + '0';
            }
        }
        if (carry) {
            ans.insert(ans.begin(), carry + '0');
        }
        return ans;
    }
};