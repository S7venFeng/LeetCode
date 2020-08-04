/* Solution(Stack) */
class Solution {
        public:
        void flatten(TreeNode* root) {
            if (!root) return;
            stack<TreeNode*> stk;
            stk.push(root);
            TreeNode *prev = nullptr;
            while (!stk.empty()) {
                TreeNode *cur = stk.top();
                stk.pop();
                if (prev != nullptr) {
                    prev->left = NULL;
                    prev->right = cur;
                }
                if (cur->right) {
                    stk.push(cur->right);
                }
                if (cur->left) {
                    stk.push(cur->left);
                }
                prev = cur;
            }
            root = prev;
            return;
        }
};

/* Solution(recur) */
class Solution {
        public:
        void flatten(TreeNode* root) {
            if (!root) return;
            flatten(root->left);
            flatten(root->right);
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right) {
                root = root->right;
            }
            root->right = tmp;
            return;
        }
};