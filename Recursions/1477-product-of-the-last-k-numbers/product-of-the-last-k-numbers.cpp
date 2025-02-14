class ProductOfNumbers {
private:
    vector<int> prefix;
    
public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            int last = prefix.back();
            prefix.push_back(last * num);
        }
    }
    
    int getProduct(int k) {

        if(k >= prefix.size()) {
            return 0;
        }
        int n = prefix.size();
        return prefix.back() / prefix[n - k - 1];
    }
};
