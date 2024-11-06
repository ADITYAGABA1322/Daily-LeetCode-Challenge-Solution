class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int maxS = nums[0] , minS = nums[0];
        int numB = __builtin_popcount(nums[0]);
        int maxPS = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            if(__builtin_popcount(nums[i]) == numB){
                maxS = max(maxS , nums[i]);
                minS = min(minS , nums[i]);
            } else{
                if(minS < maxPS) return false;
            
            maxPS = maxS;
            maxS = nums[i];
            minS = nums[i];
            numB = __builtin_popcount(nums[i]);
        }
        }
        if(minS < maxPS) return false;
        return true;
    }
};