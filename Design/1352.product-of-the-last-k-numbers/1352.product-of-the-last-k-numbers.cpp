class ProductOfNumbers {
public:
    long long res = 1;
    vector<int> v;
    int idx;
    vector<long long> mp{1};
    ProductOfNumbers() {
        idx = 1;
    }

    void add(int num) {
        if (num == 0) {
            mp.clear();
            mp.push_back(1);
        } else {
            mp.push_back(mp.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= mp.size()) return 0;
        return mp.back() / mp[mp.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */