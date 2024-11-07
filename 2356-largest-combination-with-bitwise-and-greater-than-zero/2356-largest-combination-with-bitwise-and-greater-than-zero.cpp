class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(32 , 0);
        for(auto num : candidates){
            for(int i=0; i<32; i++){
                if(num & (1<<i)) bitCount[i]++;
            }
        }
        int maxCnt = 0;
        for(auto count : bitCount){
            maxCnt = max(maxCnt , count);
        }
        return maxCnt;
    }
};