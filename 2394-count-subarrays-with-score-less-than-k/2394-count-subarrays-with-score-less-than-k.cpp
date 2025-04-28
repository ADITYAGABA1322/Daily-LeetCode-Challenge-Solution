class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // Brute Force Time Limit Exceeded 157 / 167 testcases passed
        // int n = nums.size();
        // long long cnt = 0;
        // for(int i=0; i<n; i++){
        //   long long sum = 0;
        //   for(int j=i; j<n; j++){
        //     sum += nums[j];
        //     int len = j - i + 1;
        //     if(sum * len < k) cnt++;
        //     else break;
        //   }
        // }
        // return cnt;
        // Optimized using sliding Window
        int n = nums.size();
        long long cnt = 0;
        int start = 0;
        long long sum = 0;
        for(int end = 0 ; end<n; end++){
            sum += nums[end];
            while(start <= end && sum * (end-start + 1) >= k){
                sum -= nums[start];
                start++;
            }
            cnt += (end-start+1);
        }
        return cnt;
    }
};