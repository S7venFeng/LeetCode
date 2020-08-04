class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stk;
        stk.push(INT_MIN);
        for (int i = 0; i < ast.size(); ++i) {
            if (ast[i] >= 0) {
                stk.push(ast[i]);
            } else {
                while (stk.top() > 0 && stk.top() < abs(ast[i])) {
                    stk.pop();
                }
                if (stk.top() == abs(ast[i])) {
                    stk.pop();
                } else if (stk.top() < 0) {
                    stk.push(ast[i]);
                }
            }
        }
        vector<int> ans;
        while (stk.size() != 1) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};