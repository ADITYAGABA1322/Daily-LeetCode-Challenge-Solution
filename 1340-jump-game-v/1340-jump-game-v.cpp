class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>& arr, int i , int d){
        if(dp[i] != -1) return dp[i];
        int res = 1;
        // left
        for(int j=i-1; j>=max(0 , i-d); j--){
            if(arr[j] >= arr[i]) break;
            res = max(res , 1+solve(arr , j , d));
        }
        // right
        for(int j=i+1; j<=min(n-1 , i+d); j++){
            if(arr[j] >= arr[i]) break;
            res = max(res , 1+solve(arr , j , d));
        }
        return dp[i] = res;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n+1 , -1);
        int res = 1;
        for(int i=0; i<n; i++) res = max(res , solve(arr , i , d));
        return res;
    }
};