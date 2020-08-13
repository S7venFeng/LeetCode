class Solution {
public:
    void DFS(TreeNode *root, int max, int &count) {
        if (root == NULL) return;
        if (root->val >= max) {
            count++;
            max = root->val;
        }
        DFS(root->left, max, count);
        DFS(root->right, max, count);
        return;
    }
    int goodNodes(TreeNode* root) {
        int max = -1e9;
        int count = 0;
        DFS(root, max, count);
        return count;
    }
};