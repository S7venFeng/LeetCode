class LogSystem {
    unordered_map<string, int> mp;
public:
    bool Helper(string src, string s, string e, string gra)
    {
        string year = src.substr(0, 4);
        string startY = s.substr(0, 4);
        string endY = e.substr(0, 4);
        string month = src.substr(0, 7);
        string startMon = s.substr(0, 7);
        string endMon = e.substr(0, 7);
        string day = src.substr(0, 10);
        string startD = s.substr(0, 10);
        string endD = e.substr(0, 10);
        string hour = src.substr(0, 13);
        string startH = s.substr(0, 13);
        string endH = e.substr(0, 13);
        string minute = src.substr(0, 16);
        string startMin = s.substr(0, 16);
        string endMin = e.substr(0, 16);
        string sec = src.substr(0, 19);
        string startSec = s.substr(0, 19);
        string endSec = e.substr(0, 19);

        if (gra == "Year") {
            if (year >= startY && year <= endY) return true;
            return false;
        }
        if  (gra == "Month") {
            if (month >= startMon && month <= endMon) return true;
            return false;
        }
        if  (gra == "Day") {
            if (day >= startD && day <= endD) return true;
            return false;
        }
        if  (gra == "Hour") {
            if (hour >= startH && hour <= endH) return true;
            return false;
        }
        if  (gra == "Minute") {
            if (minute >= startMin && minute <= endMin) return true;
            return false;
        }
        if  (gra == "Second") {
            if (sec >= startSec && sec <= endSec) return true;
            return false;
        }
        return false;
    }
    LogSystem() {
        mp.clear();
    }

    void put(int id, string timestamp) {
        mp[timestamp] = id;
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int> ans;
        for (auto x : mp) {
            string src = x.first;
            if (true == Helper(src, s, e, gra)) {
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */