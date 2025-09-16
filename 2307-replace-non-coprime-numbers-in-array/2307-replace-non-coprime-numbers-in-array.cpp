class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums){
            while(true){
                int x = gcd(res.empty() ? 1 : res.back(), num);
                if(x == 1) break;
                num *= res.back() / x;
                res.pop_back();
            }
            res.push_back(num);
        }
        return res;
    }
};