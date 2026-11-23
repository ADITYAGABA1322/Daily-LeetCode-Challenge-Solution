class ProductOfNumbers {
public:
    vector<int> res;
    ProductOfNumbers() {
        res.push_back(1);
    }
    
    void add(int num) {
       // res.push_back(num);
       if(num == 0){
        res.clear();
        res.push_back(1);
       } else {
        res.push_back(res.back() * num);
       }
    }
    
    int getProduct(int k) {
        // int prod = 1;
        // int n = res.size();
        // for(int i=n-k; i<n; i++) prod *= res[i];
        // return prod;
        int n = res.size();
        if(k>=n) return 0;
        return res.back() / res[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */