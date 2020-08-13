class FirstUnique {
public:
    unordered_map<int, int> s;
    vector<int> v;
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                s[nums[i]]++;
            } else {
                s[nums[i]] = 1;
                v.push_back(nums[i]);
            }
        }
    }

    int showFirstUnique() {
        for (int i = 0; i < v.size(); ++i) {
            if (s[v[i]] == 1) {
                return v[i];
            }
        }
        return -1;
    }

    void add(int value) {
        if (s.find(value) != s.end()) {
            s[value]++;
        } else {
            s[value] = 1;
            v.push_back(value);
        }
        return;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */