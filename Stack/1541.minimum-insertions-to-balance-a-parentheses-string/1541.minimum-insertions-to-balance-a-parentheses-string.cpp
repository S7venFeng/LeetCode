class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int n = s.size();
        int rCnt = 0;
        int lCnt = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (rCnt == 1) {
                    // 缺一个')'
                    ans++;
                    // 如果栈里面没有'('，需要再补一个
                    if (!stk.empty()) {
                        stk.pop();
                    } else {
                        ans++;
                    }
                    rCnt = 0;
                }
                stk.push('(');
            } else {
                rCnt++;
                if (rCnt == 2) {
                    // 需要栈里面有一个所对应
                    if (!stk.empty()) {
                        stk.pop();
                    } else {
                        // 缺一个'('
                        ans++;
                    }
                    rCnt = 0;
                }
            }
        }
        // 到达结尾，判断还缺多少个，结合栈
        if (rCnt == 1) {
            // 缺一个')'
            ans++;
            if (stk.empty()) {
                ans++;
            } else {
                stk.pop();
            }
            // 如果栈里面没有'('，需要再补一个
            while (!stk.empty()) {
                stk.pop();
                ans += 2;
            }
            rCnt = 0;
        } else if (rCnt == 0) {
            while (!stk.empty()) {
                ans += 2;
                stk.pop();
            }
        }
        return ans;
    }
};