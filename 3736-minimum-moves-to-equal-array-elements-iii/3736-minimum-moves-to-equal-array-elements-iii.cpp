class Solution {
public:
    int minMoves(vector<int>& nums) {
      //  sort(nums.begin() , nums.end());
        int  maxi = 0;
        for(auto x : nums) maxi = max(maxi , x);
        int cnt = 0;
        for(auto x: nums) cnt += maxi - x;
        return cnt;
    }
};