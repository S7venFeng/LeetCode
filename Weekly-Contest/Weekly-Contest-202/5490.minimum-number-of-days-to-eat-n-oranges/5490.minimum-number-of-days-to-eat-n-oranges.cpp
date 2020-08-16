class Solution {
public:
    unordered_map<int, int> dis;
    queue<int> q;
    void extend(int now, int num) {
        if (dis.count(num)) return;
        dis[num] = dis[now] + 1;
        q.push(num);
    }
    int minDays(int n) {
        q.push(n);
        dis[n] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            if (now == 1) {
                return dis[now] + 1;
            }
            if (now % 3 == 0) {
                extend(now, now / 3);
            }
            if (now % 2 == 0) {
                extend(now, now / 2);
            }
            extend(now, now - 1);
        }
        return -1;
    }
};