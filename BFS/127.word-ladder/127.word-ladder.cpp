class Solution {
public:
    bool helper(string &a, string &b) {
        int cnt = 0;
        if (a.size() != b.size()) return false;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                cnt++;
                if (cnt > 1) return false;
            }
        }
        return true;
    }

    int ladderLength(string begin, string end, vector<string>& wordList) {
        queue<string> q;
        q.push(begin);
        int n = wordList.size();
        vector<int> isVisited(n);
        int cnt = 0;
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            cnt++;
            for (int i = 0; i < size; ++i) {
                string now = q.front();
                q.pop();
                if (now == end) {
                    return cnt;
                }
                for (int i = 0; i < n; ++i) {
                    if (!isVisited[i] && helper(now, wordList[i])) {
                        isVisited[i] = true;
                        q.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
};