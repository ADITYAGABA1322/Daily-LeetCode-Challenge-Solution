class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        vector<int> dp(n , 1);
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1) dp[i]=  dp[i-1] + 1;
        }
        for(int i=0; i<n; i++){
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
             if (i >= k - 1) {
                if (dp[i] >= k) {
                    res.push_back(nums[dq.front()]);
                } else {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};