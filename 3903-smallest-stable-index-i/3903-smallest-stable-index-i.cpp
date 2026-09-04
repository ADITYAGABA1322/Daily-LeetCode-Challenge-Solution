class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int minEle = INT_MAX , maxEle = INT_MIN;
        vector<int> minEleFromIndex(n);
        for(int i=n-1; i>=0; i--){
            minEle = min(minEle , nums[i]);
            minEleFromIndex[i] = minEle;
        }
        for(int i=0; i<n; i++){
            maxEle = max(maxEle , nums[i]);
            minEle = minEleFromIndex[i];
            if(maxEle - minEle <= k) return i;
        }
        return -1;
    }
};