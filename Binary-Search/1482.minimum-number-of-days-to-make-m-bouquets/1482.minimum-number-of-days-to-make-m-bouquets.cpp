class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        int n = bd.size();
        int l = 1;
        int r = 0;
        for (int i = 0; i < bd.size(); ++i) {
            r = max(r, bd[i]);
        }
        int tmp = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            int mx = 0;
            for (int i = 0; i < bd.size(); ++i) {
                if (bd[i] <= mid) {
                    cnt++;
                    if (cnt == k) {
                        mx++;
                        cnt = 0;
                        if (mx == m) {
                            break;
                        }
                    }
                } else {
                    cnt = 0;
                }
            }
            if (mx >= m) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l > tmp) {
            return -1;
        } else {
            return l;
        }
    }
};