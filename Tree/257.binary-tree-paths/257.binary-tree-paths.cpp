class Solution {
public:
    void DFS(TreeNode* root, vector<int> &cur, vector<string> &ans) {
        if (root == NULL) return;
        cur.push_back(root->val);
        if (!root->left && !root->right) {
            string str = "";
            str += to_string(cur[0]);
            for (int i = 1; i < cur.size(); ++i) {
                str += "->";
                str += to_string(cur[i]);
            }
            ans.push_back(str);
        }
        if (root->left) {
            DFS(root->left, cur, ans);
            cur.pop_back();
        }
        if (root->right) {
            DFS(root->right, cur, ans);
            cur.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> cur;
        vector<string> ans;
        DFS(root, cur, ans);
        return ans;
    }
};