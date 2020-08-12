class Solution {
public:
    TreeNode* dfs(TreeNode* clo, TreeNode* ori, unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* target) {
        if (clo == NULL) return NULL;
        mp[clo] = ori;
        if (clo->val == target->val) {
            return clo;
        }
        if (clo->left) {
            TreeNode* val = 0;
            val = dfs(clo->left, ori->left, mp, target);
            if (val) return val;
        }
        if (clo->right) {
            TreeNode* val = 0;
            val = dfs(clo->right, ori->right, mp, target);
            if (val) return val;
        }
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* ori, TreeNode* clo, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> mp;
        return dfs(clo, ori, mp, target);
    }
};