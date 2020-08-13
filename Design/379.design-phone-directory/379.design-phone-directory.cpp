class PhoneDirectory {
public:
    unordered_map<int, int> m;
    vector<int> v;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            m[i] = 1;
            v.push_back(i);
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (v.empty()) return -1;
        int res = v.back();
        m[res]--;
        v.pop_back();
        return res;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (m[number]) {
            return true;
        }
        return false;
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (m[number]) return;
        v.push_back(number);
        m[number]++;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */