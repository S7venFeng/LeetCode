class Solution {
public:
    int findComplement(int num) {
        int idx = 0;
        int a = num;
        int ans = 0;
        while (a >> idx) {
            idx++;
        }
        int helper = 1;
        int cnt = 1;
        while (cnt < idx) {
            helper <<= 1;
            helper += 1;
            cnt++;
        }
        return a ^ helper;
    }
};