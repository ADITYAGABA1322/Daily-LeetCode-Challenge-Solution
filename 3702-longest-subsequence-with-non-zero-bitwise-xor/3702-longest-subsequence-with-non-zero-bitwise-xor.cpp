class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resXor = 0;
        bool allZeroes = true;
        for(auto x : nums){
            resXor = resXor ^ x;
            if(x != 0) allZeroes = false;
        }
        if(allZeroes) return 0;
        return resXor == 0 ? n-1 : n;
    }
};