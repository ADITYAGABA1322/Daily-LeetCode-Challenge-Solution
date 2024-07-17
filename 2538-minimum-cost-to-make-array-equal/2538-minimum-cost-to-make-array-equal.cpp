class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost ,  int target){
        long long res = 0;
        for(int i=0; i<nums.size(); i++){
            res += (long long)(abs(nums[i] - target)) * cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = *min_element(nums.begin() ,nums.end());
        long long right = *max_element(nums.begin() , nums.end());
        long long ans = INT_MAX;
        while(left <= right){
            int mid = left + (right - left)/2;
            long long cost1 = findCost(nums , cost , mid);
            long long cost2 = findCost(nums , cost , mid+1);
            ans = min(cost1 , cost2);
            if(cost2 > cost1) right = mid -1;
            else left = mid+1;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};