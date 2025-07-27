class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        vector<int> filtered;
        filtered.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]) filtered.push_back(nums[i]);
        }
        int cnt = 0;
        for(int i=1; i<filtered.size()-1; i++){
            if(filtered[i] > filtered[i-1] && filtered[i] > filtered[i+1]) cnt++;
            else if(filtered[i] < filtered[i-1] && filtered[i] < filtered[i+1]) cnt++;
        }
        return cnt;
    }
};