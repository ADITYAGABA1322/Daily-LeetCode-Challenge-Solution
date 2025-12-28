class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto row : grid){
            for(auto ele : row){
                if(ele < 0) cnt++;
            }
        }
        return cnt;
    }
};