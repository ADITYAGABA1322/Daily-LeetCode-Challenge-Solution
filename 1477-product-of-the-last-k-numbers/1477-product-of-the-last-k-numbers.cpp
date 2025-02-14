class ProductOfNumbers {
private:
    vector<int> preProd;
public:
    ProductOfNumbers() {
        // just intialize lets make empty ok
        preProd.push_back(1);
    }
    
    void add(int num) {
        // in that case we want to inset ele on the prduct numer just vector or map to insert ele means add nto arr ok 
        if(num == 0){
            preProd.clear();
            preProd.push_back(1);
        }
        else{
            preProd.push_back(preProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        // inthat case makes good one what we want to make predcut if we get product and rember that when we get prod and take that number means  take last 2 ele prodcut we nned to used prefix prod to  take ony last elle acc to gien k ok. and retunr the product ok in arr ok. we done it 
        int n = preProd.size();
        if(k>=n) return 0;
        return preProd.back() / preProd[n-k-1];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */