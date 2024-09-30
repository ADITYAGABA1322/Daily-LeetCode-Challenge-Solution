class CustomStack {
public:
    stack<int> stk;
    vector<int> inc;
    int maxSize;
    CustomStack(int maxSize): maxSize(maxSize) {
        inc.resize(maxSize);
    }
    void push(int x) {
        if(stk.size() < maxSize) stk.push(x); 
    }
    
    int pop() {
        if(stk.empty()) return -1;
        int idx = stk.size() - 1;
        int res= stk.top() + inc[idx];
        stk.pop();
        if(idx > 0){
            inc[idx - 1]  += inc[idx];
        }
        inc[idx] = 0;
        return res;
    }
    
    void increment(int k, int val) {
         int limit = std::min(k, (int)stk.size());
        if (limit > 0) {
            inc[limit - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */