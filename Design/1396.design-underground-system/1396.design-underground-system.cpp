class UndergroundSystem {
    unordered_map<string, unordered_map<int, vector<int>>> enter;
    unordered_map<string, unordered_map<int, vector<int>>> exit;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        if (enter.find(stationName) == enter.end()) {
            enter[stationName] = unordered_map<int, vector<int>>();
        }
        if (enter[stationName].find(id) == enter[stationName].end()) {
            enter[stationName][id] = vector<int>({t});
        } else {
            enter[stationName][id].push_back(t);
        }
    }

    void checkOut(int id, string stationName, int t) {
        if (exit.find(stationName) == exit.end()) {
            exit[stationName] = unordered_map<int, vector<int>>();
        }
        if (exit[stationName].find(id) == exit[stationName].end()) {
            exit[stationName][id] = vector<int>({t});
        } else {
            exit[stationName][id].push_back(t);
        }
    }

    double getAverageTime(string startStation, string endStation) {
        double total = 0;
        int cnt = 0;

        for (const auto & r : enter[startStation]) {
            int id = r.first;
            if (exit[endStation].find(id) != exit[endStation].end()) {
                auto v1 = r.second;
                auto v2 = exit[endStation][id];
                const int n = min(v1.size(), v2.size());
                for (int i = 0; i < n; i++) {
                    total += (v2[i] - v1[i]);
                    cnt++;
                }
            }
        }

        return total / cnt;
    }
};