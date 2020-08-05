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

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2);
        }
        vector<int> res(2);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 偷
        res[0] = root->val + left[1] + right[1];
        // 不偷
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};