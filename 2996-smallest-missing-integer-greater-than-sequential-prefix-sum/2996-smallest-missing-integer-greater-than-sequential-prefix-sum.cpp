class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin() , nums.end());
        int total = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                total += nums[i];
            } else break;
        }
        while(st.count(total)) total += 1;
        return total;
    }
};