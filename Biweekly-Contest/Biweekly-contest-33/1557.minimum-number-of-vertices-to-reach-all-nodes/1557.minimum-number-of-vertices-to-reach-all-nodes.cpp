class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> d(n);
        for (int i = 0; i < edges.size(); ++i) {
            d[edges[i][1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!d[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};