class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int , ll> indexCnt , indexSum;
        int n = nums.size();
        vector<ll> arr(n , 0);
        for(int i=0; i<n; i++){
            ll freq = indexCnt[nums[i]];
            ll sum = indexSum[nums[i]];

            arr[i] += freq*i - sum;
            indexCnt[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        indexSum.clear();
        indexCnt.clear();

        for(int i=n-1; i>=0; i--){
            ll freq = indexCnt[nums[i]];
            ll sum = indexSum[nums[i]];

            arr[i] += sum - freq*i;
            indexCnt[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return arr;
    }
};