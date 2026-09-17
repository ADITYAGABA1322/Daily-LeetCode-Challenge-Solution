class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int currSum = 0 , ans = INT_MAX , i=0;
        vector<int> dp(arr.size() , INT_MAX);
        for(int j=0; j<arr.size(); j++){
            currSum += arr[j];
            while(currSum > target){
                currSum -= arr[i];
                i++;
            }
            if(j>0) dp[j] = dp[j-1];
            if(currSum == target){
                if(i>0 && dp[i-1] != INT_MAX) ans = min(ans , dp[i-1] + j-i+1);
                dp[j] = min(dp[j] , j-i+1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};