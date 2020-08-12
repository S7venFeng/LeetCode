class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = length;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] = a[i] - a[i - 1];
        }
        for (int i = 0; i < updates.size(); ++i) {
            b[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < n) {
                b[updates[i][1] + 1] -= updates[i][2];
            }
            a[0] = b[0];
        }
        for (int j = 1; j < n; ++j) {
            a[j] = a[j - 1] + b[j];
        }
        return a;
    }
};