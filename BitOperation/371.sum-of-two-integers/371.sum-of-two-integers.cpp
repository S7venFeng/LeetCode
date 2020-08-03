class Solution {
public:
    int getSum(int a, int b) {
        // if (!b) return a;
        int res = a ^ b;
        if (!(a & b)) return res;
        unsigned int carry = (unsigned int)(a & b) << 1;
        return getSum(res, carry);
    }
};