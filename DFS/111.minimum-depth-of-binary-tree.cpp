class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int cnt = q.size();
            ans++;
            while (cnt) {
                TreeNode* now = q.front();
                q.pop();
                if (!now->left && !now->right) {
                    return ans;
                }
                if (now->left) {
                    q.push(now->left);
                }
                if (now->right) {
                    q.push(now->right);
                }
                cnt--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->right) {
            return minDepth(root->left) + 1;
        }
        if (!root->left && root->right) {
            return minDepth(root->right) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};