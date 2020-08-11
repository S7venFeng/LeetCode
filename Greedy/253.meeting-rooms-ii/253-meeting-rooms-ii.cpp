class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& iva) {
        if (iva.size() == 0) return 0;
        sort(iva.begin(), iva.end());
        vector<int> room;
        int ans = 1;
        room.push_back(iva[0][1]);
        bool flag = false;
        for (int i = 1; i < iva.size(); ++i) {
            flag = false;
            for (auto &x : room) {
                if (iva[i][0] >= x) {
                    x = iva[i][1];  // 如果发现没有交集，则取代上一个会议室
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                room.push_back(iva[i][1]);
                ans++;
            }
        }
        return ans;
    }
};