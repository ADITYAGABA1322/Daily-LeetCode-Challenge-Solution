class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endCnt(n , 0);
        for(int i=0; i<n; i++){
            int j = n -1 , cnt = 0;
            while(j>=0 && grid[i][j] == 0){
                cnt++;
                j--;
            }
            endCnt[i] = cnt;
        }

        int steps = 0;
        for(int i=0; i<n; i++){
            int need = n - i - 1;
            int j = i;
            while(j<n && endCnt[j] < need){
                j++;
            }
            if(j == n) return -1;
            steps += j-i;
            while(j>i){
                swap(endCnt[j] , endCnt[j-1]);
                j--;
            }
        }
        return steps;
    }
};