class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = stk.top();
        stk.pop();
        int res = node->val;
        if (node->right) {
            node = node->right;
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stk.empty()) {
            return false;
        }
        return true;
    }
};