class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // lets start a problme what we give like 2 string sok we need to that is string s2 is subseq of sq or not and i repeat again its about subsequence not subarray ok. focus  on this line ok. first and then listen creafully what want to do now we start with brute force simple and analyze the algo ok. first for brute force what we do like we want to check its about pattern but its not pattern because we take the  subsequence ok. and we form a string if we dete in res string if we delete some part of str and str2 form ok we nned to use 2 loops and check if str2 is substr iof s or notmeans somthing like this ok. and if we find this one take lots  of time to run becuase using 2 lops and using just check the in both str and form it or not now we want to optimize the solution and we use the LCS means longest common subseq ok by using 2d dp and stre var and check eq or not ok  
        int n = str1.size() , m = str2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        string scs;
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                scs += str1[i-1];
                --i;
                --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1];
                --i;
            }
            else{
                scs += str2[j-1];
                --j;
            }
        }
        while(i>0){
            scs += str1[i-1];
            i--;
        }
        while(j>0){
            scs += str2[j-1];
            j--;
        }
        reverse(scs.begin() , scs.end());
        return scs;
    }
};