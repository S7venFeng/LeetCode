class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode *now = s.top();
            ans.push_back(now->val);
            s.pop();
            if (now->right) {
                s.push(now->right);
            }
            if (now->left) {
                s.push(now->left);
            }
        }
        return ans;
    }
};