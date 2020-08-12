class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            long long mid = (r + l) >> 1;
            int cnt = 0;
            for (auto x : piles) {
                if (x <= mid) {
                    cnt++;
                } else if (x % mid == 0){
                    cnt += x / mid;
                } else {
                    cnt += x / mid + 1;
                }
            }
            if (cnt <= H) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};