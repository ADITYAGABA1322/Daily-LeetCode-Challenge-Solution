class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for(auto n : nums){
            while(!s.empty() && s.back() > n){
                s.pop_back();
            }
            if(n == 0) continue;
            if(s.empty() || s.back() < n){
                res++;
                s.push_back(n);
            }
        }
        return res;
    }
};