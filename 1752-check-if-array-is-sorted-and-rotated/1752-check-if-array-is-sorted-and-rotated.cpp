class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() , drpCnt = 0l;
        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i+1)%n]) drpCnt++;
            if(drpCnt>1) return false;
        }
        return true;
    }
};