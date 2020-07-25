class Solution {
public:
    int countOdds(int l, int r) {
        int cnt = 0;
        for (int i = l; i <= r; ) {
            if (i % 2 != 0) {
                cnt++;
                i += 2;
            } else {
                i++;
            }
        }
        return cnt;
    }
};