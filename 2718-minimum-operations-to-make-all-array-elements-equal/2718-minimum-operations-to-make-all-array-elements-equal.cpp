class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size() , m = queries.size();
        sort(nums.begin() , nums.end());
        vector<long long> psum(n+1 , 0)  , res(m , 0);
        for(int i=1; i<=nums.size(); i++) {
            psum[i] = psum[i-1] + nums[i-1];
           // cout<<psum[i]<<endl;
        }
        for(int i=0; i<m; i++){
            int query = queries[i];
            int pos = lower_bound(nums.begin() , nums.end() , query) - nums.begin();
           // cout<<pos<<endl;
            long long lpos = 1LL * pos * query - psum[pos];
           // cout<<lpos<<endl;
            long long rpos = (psum[n] - psum[pos]) - 1LL * query * (n-pos);
           // cout<<rpos<<endl;
            res[i] = lpos + rpos;
        }
        return res;
    }
};