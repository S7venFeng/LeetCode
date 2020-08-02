class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        p.resize(n);
        string ans;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        vector<vector<char>> v(n);
        for (auto items : pairs) {
            if (find(items[0]) != find(items[1])) {
                p[find(items[0])] = find(items[1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            v[find(i)].push_back(s[i]);
        }
        for (int i = 0; i < n; ++i) {
            sort(v[i].rbegin(), v[i].rend());
        }

        for (int i = 0; i < n; ++i) {
            ans += v[find(i)].back();
            v[find(i)].pop_back();
        }
        return ans;
    }
};