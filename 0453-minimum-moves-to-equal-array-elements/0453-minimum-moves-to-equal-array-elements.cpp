class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX , diff = 0;
        for(auto x: nums) mini = min(mini , x);
        for(auto x: nums) diff += x-mini;
        return diff;
    }
};