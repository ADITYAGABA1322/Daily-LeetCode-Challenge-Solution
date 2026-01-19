class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size() ,  n = mat[0].size();
        vector<vector<int>> prefixSum(m+1 , vector<int>(n+1 , 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefixSum[i][j] = prefixSum[i-1][j] +  prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int low = 0 , high = min(m , n) , res = 0;
        while(low<= high){
            int mid = low + (high - low) / 2;
            if(check(prefixSum , mid ,  threshold , m , n)){
                res = mid;
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        return res;
    }

    bool check(vector<vector<int>>& prefixSum , int k , int threshold , int m , int n){
        if(k == 0) return true;
        for(int i=k; i<=m; i++){
            for(int j=k; j<=n; j++){
                int sum = prefixSum[i][j] - prefixSum[i-k][j] - prefixSum[i][j-k] + prefixSum[i-k][j-k];
                 if (sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
};