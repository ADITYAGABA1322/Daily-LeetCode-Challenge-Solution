class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCnt = 0 , longestWindow = 0 , start = 0;
        for(int i=0; i<n; i++){
            zeroCnt += (nums[i] == 0);
            while(zeroCnt > 1){
                zeroCnt -= (nums[start] == 0);
                start++;
            }
            longestWindow = max(longestWindow , i - start);
        }
        return longestWindow;
    }
};