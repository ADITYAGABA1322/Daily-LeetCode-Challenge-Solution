class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            if(nums[i] < k) return -1;
            if(nums[i] > k)   st.insert(nums[i]);
        }
        return st.size();
    }
};