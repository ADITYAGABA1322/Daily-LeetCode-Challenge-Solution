class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size() , maxW = 0;
        stack<int> st;
        for(int i=0; i<n-1; i++){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        for(int j=n-1; j>=0; j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                maxW = max(maxW , j - st.top());
                st.pop();
            }
        }
        return maxW;
    }
};