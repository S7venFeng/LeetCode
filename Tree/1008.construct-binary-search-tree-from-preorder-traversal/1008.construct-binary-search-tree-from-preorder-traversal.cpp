class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (!preorder.size()) {
            return NULL;
        }
        vector<int> left;
        vector<int> right;
        int val = preorder[0];
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i) {
            if (preorder[i] < val) {
                left.push_back(preorder[i]);
            } else {
                right.push_back(preorder[i]);
            }
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};