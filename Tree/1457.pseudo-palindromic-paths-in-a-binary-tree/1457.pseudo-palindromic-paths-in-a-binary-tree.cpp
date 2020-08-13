class Solution {
public:
    const int MAX_SIZE = 100000;
    void DFS(TreeNode *root, vector<int> &vec, int &ans) {
        if (root->left == NULL && root->right == NULL) {
            if (isPalin(vec)) {
                ans++;
            }
            return;
        }
        if (root->left) {
            vec.push_back(root->left->val);
            DFS(root->left, vec, ans);
            vec.pop_back();
        }
        if (root->right) {
            vec.push_back(root->right->val);
            DFS(root->right, vec, ans);
            vec.pop_back();
        }
        return;
    }

    bool isPalin (vector<int> v)
    {
        int len = v.size();
        bool isOdd = len % 2 == 0 ? false : true;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] == v[i + 1]) {
                len -= 2;
                ++i;
            }
        }
        if (isOdd == true && len == 1) {
            return true;
        } else if(isOdd == false && len == 0) {
            return true;
        } else {
            return false;
        }
        return false;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> vec;
        int ans = 0;
        vec.push_back(root->val);
        DFS(root, vec, ans);
        return ans;
    }
};