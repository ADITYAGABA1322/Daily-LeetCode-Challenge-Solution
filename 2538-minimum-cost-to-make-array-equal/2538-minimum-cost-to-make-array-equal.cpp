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
        // long long left = *min_element(nums.begin() ,nums.end());
        // long long right = *max_element(nums.begin() , nums.end());
        // long long ans = INT_MAX;
        // while(left <= right){
        //     int mid = left + (right - left)/2;
        //     long long cost1 = findCost(nums , cost , mid);
        //     long long cost2 = findCost(nums , cost , mid+1);
        //     ans = min(cost1 , cost2);
        //     if(cost2 > cost1) right = mid -1;
        //     else left = mid+1;
        // }
        // return ans == INT_MAX ? 0 : ans;
        // // 2nd one

        // long long l = 1 , r = 1000000 , cost1 = 0 , cost2 = 0;
        // while(l<r){
        //     int m = l + (r-l)/2;
        //     cost1 = cost2 = 0;
        //     for(int i=0; i<nums.size(); i++){
        //         cost1 += (long long) cost[i] * abs(nums[i] - m);
        //         cost2 += (long long) cost[i] * abs(nums[i] - (m+1));
        //     }
        //     if(cost2 > cost1) r = m;
        //     else l = m+1;
        // }
        // return min(cost1 , cost2);

         // 3rd one weioghted median with binary search
        long long total = accumulate(begin(cost),end(cost) , 0LL) , res = 0;
        long long l = 1 , r = 1000000;
        while(l<r){
            long long sum = 0 ,  m = l + (r-l)/2;
            for(int i=0; i<nums.size(); i++)
                sum += nums[i] <= m ? cost[i] : 0;
            if(sum <= total/2) l = m+1;
            else r= m;
        }
        for(int i=0; i<nums.size(); i++) res += (long long) cost[i] * abs(nums[i] - l);
        return res;
    }
};