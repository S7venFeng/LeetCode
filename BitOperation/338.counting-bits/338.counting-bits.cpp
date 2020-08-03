class Solution {
public:
    int helper(int num) {
        int res = 0;
        while (num > 0) {
            num -= (num & (-num));
            res++;
        }
        return res;
    }
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; ++i) {
            int tmp = helper(i);
            ans[i] = tmp;
        }
        return ans;
    }
};