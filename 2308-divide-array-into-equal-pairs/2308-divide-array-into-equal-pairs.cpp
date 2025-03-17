class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        // nums consisting of 2 * n integers
        unordered_map<int , int> mp;
        for(auto n : nums) mp[n]++;
        for(auto it : mp){
            if(it.second % 2 != 0) return false;
        }
        return true;
        // if(n/2 % 2 != 0) return true;
        // else return false;
    }
};