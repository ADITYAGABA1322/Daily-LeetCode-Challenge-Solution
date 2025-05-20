class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1 , 0);
        for(auto q : queries ){
            int l = q[0] , r = q[1];
            diff[l] +=1;
            diff[r+1] -=1;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += diff[i];
            if(nums[i] > cnt) return false;
        }
        return true;
    }
};