class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        const int N = 1e9;
        int l = 0, r = N;
        int n = pos.size();
        sort(pos.begin(), pos.end());
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int last = pos[0];
            int cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (pos[i] - last >= mid) {
                    cnt++;
                    last = pos[i];
                }
            }
            if (cnt >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};