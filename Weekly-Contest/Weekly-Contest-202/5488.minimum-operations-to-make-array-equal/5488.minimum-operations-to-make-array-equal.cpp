class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = 2 * i + 1;
            sum += arr[i];
        }
        int des = sum / n;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = abs(arr[i] - des);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for (auto x : ans) {
            res += x;
        }
        return res;
    }
};