class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size() , cols = strs[0].size();
        int ans = 1;
        vector<int> dp(cols , 1);
        for(int i=0; i<cols; i++){
            for(int j=0; j<i; j++){
                bool isValid = true;
                for(int k=0; k<rows; k++){
                    if(strs[k][j] > strs[k][i]){
                        isValid = false;
                        break;
                    }
                }
                if(isValid){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
            ans = max(ans , dp[i]);
        }
        return cols - ans;
    }
};