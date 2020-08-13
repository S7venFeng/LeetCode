class Leaderboard {
public:
    map<int, int> lt;
    Leaderboard() {
        lt.clear();
    }

    void addScore(int playerId, int score) {
        if (lt[playerId]) {
            lt[playerId] += score;
        } else {
            lt[playerId] = score;
        }
        return;
    }

    int top(int K) {
        vector<pair<int, int>> v;
        for (auto x : lt) {
            v.push_back(x);
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second;
        });
        int res = 0;
        int cnt = 0;
        for (auto x : v) {
            res += x.second;
            cnt++;
            if (cnt == K) return res;
        }
        return res;
    }

    void reset(int playerId) {
        lt[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */