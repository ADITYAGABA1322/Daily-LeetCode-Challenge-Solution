class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size() , false);
        vector<int> pre(nums.size() , 0);
        pre[0]= 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] % 2 == nums[i-1] % 2) pre[i] = pre[i-1]+1;
            else pre[i] = pre[i-1];
        }
        for(int i=0; i<queries.size(); i++){
            vector<int> q = queries[i];
            int st = q[0] , end = q[1];
            ans[i] = pre[end] - pre[st] == 0;
        }
        return ans;
    }
};