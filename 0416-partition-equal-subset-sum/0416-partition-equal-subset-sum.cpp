class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        // int sum = 0;
        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     sum += nums[i];
        // }
        // if(sum == nums.back()) return true;
        // else return false;
        // the approach is not wokring because  this one tke large lest elel rest of sum if equal return true else false so what the next approach like i said this one partition subset as subsets we go with dp but dp works here lets start with intution  but how dp leet go thrugh the question first we want to check the way so that dp[i] and dp[i+1] of both sums are precomputed acc tot hat their sum is equal to both dp[i] and dp[i+1] ok so how should we start we 1d dp of n size what this dp its intitlize and then start sum of subsets acc to that  dp[i] += dp[i+1] or dp[i+1]+1 ot dp[i] + 1 as acc tot his situation we want ot sum and check that ok 
        int n = nums.size();
        int totalSum = 0;
        for(auto num : nums) totalSum += num;
        if(totalSum % 2 != 0 ) return false;
        int targetSum = totalSum/2;
        vector<bool> dp(targetSum+1 , 0);
        dp[0] = true;
        for(auto num : nums){
            for(int j=targetSum; j>=num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[targetSum];
    }
};