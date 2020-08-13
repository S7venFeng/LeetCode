class Solution {
public:
    TreeNode* treeReverse(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> inLeftOrder;
        vector<int> inRightOrder;
        int inIndex = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                inIndex = i;
                break;
            }
            inLeftOrder.push_back(inorder[i]);
        }
        for (int i = inIndex + 1; i < inorder.size(); ++i) {
            inRightOrder.push_back(inorder[i]);
        }
        int preIndex = inLeftOrder.size();
        vector<int> preLeftOrder;
        vector<int> preRightOrder;
        for (int i =  1; i < preIndex + 1; ++i) {
            preLeftOrder.push_back(preorder[i]);
        }
        for (int i =  preIndex + 1; i < preorder.size(); ++i) {
            preRightOrder.push_back(preorder[i]);
        }
        root->left = treeReverse(preLeftOrder, inLeftOrder);
        root->right = treeReverse(preRightOrder, inRightOrder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        TreeNode *root = treeReverse(preorder, inorder);
        return root;
    }
};