class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Brute Force TLE 622 / 633 testcases passed
        int n = nums.size();
        long long count = 0;
        int max_ele = *max_element(nums.begin() , nums.end());
        int start = 0;
         int maxCount = 0;
        // for(int i=0; i<n; i++){
        //     int maxCount = 0;
        //     for(int j=i; j<n; j++){
        //         if(nums[j] ==  max_ele) maxCount++;
        //         if(maxCount >= k) count++;
        //     }
        // }
        for(int end = 0; end<n; end++){
            if(nums[end] == max_ele)   maxCount++;
            while(maxCount >= k){
               count += n-end;
               if(nums[start] == max_ele){
                    maxCount--;
               }
               start++;
            }
            
        }
        return count;
    }
};