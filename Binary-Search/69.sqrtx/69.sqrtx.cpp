class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            long long res = mid * mid;
            if (res <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};