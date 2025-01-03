class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // arr of nums  we valid  split at idx i sum of first i +1 is >= sum of last n - i -1 ele and atleast 1 ele to the right of i retunr no of valid splits in nums this one simple we use prefix we create an vector<int> pre and in for loop tkae pre[i+1] for += pre[i] and itearte nums and split fomr starting then check the sum ok in prefix sum ok 
        int n = nums.size() , cnt = 0;
        vector<long long> pre(n+1 , 0);
        for(int i=0; i<n; i++) pre[i+1] = pre[i] + nums[i];
        for(int i=0; i<n-1; i++){
            long long lSum = pre[i+1] , rSum = pre[n] - pre[i+1];
            if(lSum >= rSum) cnt++;
        }
        return cnt;
    }
};