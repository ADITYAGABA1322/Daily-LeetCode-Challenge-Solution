class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string , int> rowCount;
        int maxRows = 0;
        for(auto row : matrix){
            string normalizeRows;
            for(auto val : row){
                normalizeRows += (val == row[0]) ? '0' : '1'; 
            }
            rowCount[normalizeRows]++;
            maxRows = max(maxRows , rowCount[normalizeRows]);
        }
        return maxRows;
    }
};