/* sliding window */
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mn = INT_MAX;
        int n = nums.size();
        multimap<int, int> numMap; //存储各个数字位于哪个组中
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                numMap.insert({nums[i][j], i});
            }
        }
        unordered_map<int, int> vecCount; //存储每个组里面数字个数，如果个数从1变为0则总cnt减1，如果个数从0变为1则总cnt数加1
        int cnt = 0;
        vector<int> ans(2);
        auto i = numMap.begin();
        auto j = numMap.begin();
        while (i != numMap.end()) {
            if (!vecCount[i->second]) {
                // 该组数字个数从0变为1，总cnt加1
                cnt++;
            }
            vecCount[i->second]++;
            while (cnt == n) {
                if ((i->first - j->first < mn)) {
                    mn =  i->first - j->first;
                    ans[0] = j->first;
                    ans[1] = i->first;
                }
                vecCount[j->second]--;
                if (!vecCount[j->second]) {
                    // 该组数字个数从1变为0，总cnt加0
                    cnt--;
                }
                j++;
            }
            ++i;
        }
        return ans;
    }
};

/* heap(priority_queue) */
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int rangeLeft = 0;
        int rangeRight = INT_MAX;
        int maxValue = INT_MIN;
        int minValue = 0;
        vector<int> next(n); //指向每个数组的当前元素，初始为0
        auto cmp = [&](const int &u, const int &v){
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }

        while (!pq.empty()) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeRight = maxValue;
                rangeLeft = minValue;
            }
            next[row]++;
            if (next[row] > nums[row].size() - 1) break;
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }
        return {rangeLeft, rangeRight};
    }
};