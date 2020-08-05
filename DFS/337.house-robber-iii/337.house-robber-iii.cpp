class Solution {
public:
    unordered_map<TreeNode *, int> m;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        if (m[root]) return m[root];
        int money = root->val;
        if (root->left) {
            money += dfs(root->left->left) + dfs(root->left->right);
        }
        if (root->right) {
            money += dfs(root->right->left) + dfs(root->right->right);
        }
        money = max(money, dfs(root->left) + dfs(root->right));
        m[root] = money;
        return money;
    }
    int rob(TreeNode* root) {
        return dfs(root);
    }
};