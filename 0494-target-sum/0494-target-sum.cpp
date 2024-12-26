class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // we want build cnt of expression first i think using stack but when see topic dp and backtracking but dp is efficent in this case because backtracking use  rectuseion which is not efficent but we go with both approaches ok the problem we ereturn expression of -+or+- to used all ele nums and to make it like target the rpoblme an back and through means first check then back to if it target or not than thorugh ok if see that case inwihch the formula first we stat with i and j for loop whcihc checks to evaulate a exprssion and check it s eqaul o rnot this one sued in dp and for backtracjnoig we create a return helper just do i permutation or in combination using backtracking ok  
        // return backtrack(nums , target , 0 , 0);
   // }
    // private:
    //     int backtrack(vector<int>& nums , int target , int idx , int currSum){
    //         if(idx == nums.size()) return currSum == target ? 1 : 0; 
    //         int add = backtrack(nums , target , idx + 1 , currSum + nums[idx]);
    //         int sub = backtrack(nums , target , idx + 1 , currSum - nums[idx]);
    //         return add+sub;
    //     }

    // using dp

    int sum = 0;
    for(auto num : nums) sum += num;
    if(abs(target) > sum || (sum + target) %2 != 0) return 0;
    int newT = (sum + target) / 2;
    return subSetSum(nums , newT);
    }
    private:
    int subSetSum(vector<int>& nums , int target){
        vector<int> dp(target+1 , 0);
        dp[0] = 1;
        for(auto num : nums){
            for(int j=target; j>=num; j--){
                dp[j] += dp[j-num];
            }
        }
        return dp[target];
    }
};