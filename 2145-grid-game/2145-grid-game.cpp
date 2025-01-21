class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // we have a grid row col reprsents a points pos rc on mat and we want tos atrt robot at all four direction and there are 2 robots  The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot. we need to find this to use sum for max and min to check the no of points by 2nd  robot 
        // Appraoch : intiaize the m and and use the prefix sum to find optimal like we know need to traverse calculate max sum in first mat and aacreinf t we intilize that points to 0 and traverse the path in 2nd ,at and return sum of 2nd mat ok 
        int n =  grid[0].size();
        vector<long> pTop(n+1 , 0) , pBottom(n+1 , 0);
        for(int i=0; i<n; i++){
            pTop[i+1] = pTop[i] + grid[0][i];
        }
        for(int i=0; i<n; i++){
            pBottom[i+1] = pBottom[i] + grid[1][i];
        }
        long long res = LLONG_MAX;
        for(int i=0; i<n; i++){
            long long pointsTop = pTop[n] - pTop[i+1];
            long long pointsBottom = pBottom[i];
            long long pointsBySecRobo = max(pointsTop , pointsBottom); 
            res = min(res , pointsBySecRobo);
        }
        return res;
    }
};