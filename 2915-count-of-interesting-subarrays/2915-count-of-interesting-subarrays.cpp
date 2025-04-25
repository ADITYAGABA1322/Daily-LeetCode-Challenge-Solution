class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // you are given 0 indexed array nums and an integer modulo and an int k and your task is to find the cnt of intersting subarrays ok. a nums[l to r] is intersting only cnt be the no of indices i in the range [l,r] is such that nums[i] % modulo == k the cnt % modulo == k lets take an example of nums [3,2,4] modula is 2 and k = 1 lets tkae first one 3 % 2 == 1 and k = 1 so make cnt = 1 and then cnt % mod == k i.e 1 % 2 == 1 == k means we find that res ok add the cnt into and move forward lets take [3,2]. which is also  one element follow that constion i = 0 again so cnt = 1 in that  and in last [3,2,4]. similar way ok. lets start build the approach you know its subarray solve with sliding window is ease for this and we want to perfrom some math means simple check that cnt and main res we add this cnt to my res when ever i cnt in my subarray ok so we return total in last and shoudlwe use map here to insert and update it by freq of element or check the index 
        // brute force (TLE)
        // int n = nums.size();
        // long long res = 0;
        // for(int i=0; i<n; i++){
        //     int cnt = 0;
        //     for(int j=i; j<n; j++){
        //         if(nums[j] % modulo == k) cnt++;
        //         if(cnt % modulo == k) res++;
        //     }
        // }
        // return res;
        // prefix O(n)
        int n = nums.size();
        vector<int> tranformed(n);
        for(int i=0; i<n; i++) tranformed[i] = (nums[i] % modulo == k) ? 1 : 0;
        unordered_map<int , int> prefixCnt;
        prefixCnt[0] = 1;
        long long res = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt = (cnt + tranformed[i]) % modulo;
            int target = (cnt - k + modulo) % modulo;
            res += prefixCnt[target];
            prefixCnt[cnt]++;
        }
        return res;
    }
};