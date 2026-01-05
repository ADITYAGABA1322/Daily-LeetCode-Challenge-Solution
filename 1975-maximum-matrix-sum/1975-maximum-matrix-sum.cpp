class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minVal = INT_MAX , negativeCnt = 0;
        for(auto r : matrix){
            for(auto val: r){
                totalSum += abs(val);
                if(val < 0) negativeCnt++;
                minVal = min(minVal , abs(val));
            }
        }
        if(negativeCnt % 2 != 0) totalSum -= 2 * minVal;
        return totalSum;
    }
};