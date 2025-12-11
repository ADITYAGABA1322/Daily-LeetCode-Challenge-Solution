class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n+1) , minRow(n+1 , n+1) , maxCol(n+1) , minCol(n+1 , n+1);
        for(auto b: buildings){
            int x = b[0] , y = b[1];
            maxRow[y] = max(maxRow[y] , x);
            minRow[y] = min(minRow[y] , x);
            maxCol[x] = max(maxCol[x] , y);
            minCol[x] = min(minCol[x] , y);
        }
        int res = 0;
        for(auto b : buildings){
            int x = b[0] , y = b[1];
            if(x>minRow[y] && x < maxRow[y]  && y > minCol[x] && y > minCol[x] && y< maxCol[x]){
                res++;
            }
        }
        return res;
    }
};