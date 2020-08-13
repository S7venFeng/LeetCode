class Cashier {
    // vector<int> pro;
    unordered_map<int, int> pri;
    double dis;
    int yes;
    int cnt;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        dis = (100 - discount) * 0.01;
        yes = n;
        for (int i = 0; i < products.size(); ++i) {
            pri[products[i]] = prices[i];
        }
        cnt = 0;
    }

    double getBill(vector<int> product, vector<int> amount) {
        int m = product.size();
        cnt++;
        double x = 0;
        for (int i = 0; i < m; ++i) {
            int b = amount[i];
            x += b * pri[product[i]];
        }
        if (cnt % yes == 0) {
            x = x * dis;
        }
        return (double)x;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */