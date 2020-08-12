class Solution {
public:
    void dfs(TreeNode* &root, string &s) {
        if (s == "") {
            root = new TreeNode();
            root = NULL;
            return;
        };
        int i = 0;
        while (s[i] != '(' && i < s.size()) {
            ++i;
        }
        cout <<"q" << s << endl;
        string valS = s.substr(0, i);
        cout << valS;
        root = new TreeNode(atoi(valS.c_str()));
        int j = s.size() - 1;
        stack<int> stk;
        int cnt = 0;
        string left;
        string right;
        while (j >= 0) {
            if (s[j] == ')') {
                stk.push(j);
            } else if (s[j] == '(') {
                int idx = stk.top();
                stk.pop();
                if (stk.empty()) {
                    if (!cnt) {
                        right = s.substr(j + 1, idx - j - 1);
                        cnt++;
                    } else {
                        left = s.substr(j + 1, idx - j - 1);
                        break;
                    }
                }
            }
            --j;
        }
        if (left == "" && right != "") {
            left = right;
            right = "";
        }
        dfs(root->left, left);
        dfs(root->right, right);
        return;
    }

    TreeNode* str2tree(string s) {
        TreeNode *root;
        dfs(root, s);
        return root;
    }
};