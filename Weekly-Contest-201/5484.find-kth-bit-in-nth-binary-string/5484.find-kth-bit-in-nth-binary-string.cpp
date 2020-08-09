class Solution {
public:
    char findKthBit(int n, int k) {
        if (!k) return ' ';
        vector<string> arr(21);
        string s = "";
        arr[1] = "0";
        arr[2] = "011";
        for (int i = 3; i <= n; ++i) {
            string tmp = arr[i - 1];
            int m = tmp.size();
            string now;
            while (m) {
                int num = tmp[m - 1];
                int num2 = !(num & 1);
                now += num2 + '0';
                m--;
            }
            arr[i] = arr[i - 1] + '1' + now;
        }
        return arr[n][k - 1];
    }
};