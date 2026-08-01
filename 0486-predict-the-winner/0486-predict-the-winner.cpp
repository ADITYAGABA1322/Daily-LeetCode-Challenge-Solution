class Solution {
public:

  // bool predictTheWinner(vector<int>& nums) {
    //     int n = nums.size();
    //     int total = accumulate(nums.begin() , nums.end() , 0);
    //     int player1_score = solve(0 , n-1 , nums);
    //     int player2_score = total - player1_score;
    //     return player1_score >= player2_score;
    // }

    // int solve(int i , int j , vector<int>& nums){
    //     if(i > j) return 0;
    //     if(i == j) return nums[i];
    //     // Max - Min Game Strategy
    //     int take_i = nums[i] + min(solve(i+2 , j , nums) , solve(i+1 , j-1 , nums));
    //     int take_j = nums[j] + min(solve(i , j-2, nums) , solve(i+1 , j-1 , nums));
    //     return max(take_i , take_j);
    // }

    // memo + recursion II
    int dp[23][23];
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0 , n-1) >= 0;
    }

    int solve(vector<int>& nums , int i , int j){
        if(i>j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int take_i = nums[i] - solve(nums , i+1 , j);
        int take_j = nums[j] - solve(nums , i , j-1);
        return dp[i][j] = max(take_i , take_j);
    }
    
};