class Solution {
public:
    int helper(uint32_t num) {
        int res = 0;
        while (num) {
            num -= (num & (-num));
            res++;
        }
        return res;
    }
    int hammingWeight(uint32_t n) {
        return  helper(n);
    }
};