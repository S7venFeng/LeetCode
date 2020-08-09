class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        bool flag = false;
        while (true) {
            flag = false;class Solution {
            public:
                string makeGood(string s) {
                    int n = s.size();
                    bool flag = false;
                    while (true) {
                        flag = false;
                        for (int i = 0; i < n - 1; ++i) {
                            if (s[i] - s[i + 1] == 32 || s[i + 1] - s[i] == 32) {  // 两个字符互为大小写的话，ASCII码值相差32
                                s.erase(s.begin() + i);
                                s.erase(s.begin() + i); // 注意删除第一个i后，第二个i即是原来i+1的下标位置
                                flag = true;
                                break;
                            }
                        }
                        if (!flag) return s;  // 不满足条件则直接返回答案
                    }
                    return s;
                }
            };
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] - s[i + 1] == 32 || s[i + 1] - s[i] == 32) {  // 两个字符互为大小写的话，ASCII码值相差32
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i); // 注意删除第一个i后，第二个i即是原来i+1的下标位置
                    flag = true;
                    break;
                }
            }
            if (!flag) return s;  // 不满足条件则直接返回答案
        }
        return s;
    }
};

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.size();
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < n; ++i) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }
            char c = stk.top();
            if (s[i] - c == 32 || c - s[i] == 32) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};