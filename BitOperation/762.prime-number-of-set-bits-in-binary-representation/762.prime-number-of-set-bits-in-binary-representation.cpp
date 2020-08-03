class Solution {
public:
    int helper(int num) {
        int res = 0;
        while (num) {
            num -= num & (-num);
            res++;
        }
        return res;
    }
    int countPrimeSetBits(int L, int R) {
        vector<int> arr;
        set<int> s{2, 3, 5, 7, 11, 13, 17, 19};
        for (int i = L; i <= R; ++i) {
            arr.push_back(helper(i));
        }
        int ans = 0;
        for (auto x : arr) {
            if (s.count(x)) {
                ans++;
            }
        }
        return ans;
    }
};