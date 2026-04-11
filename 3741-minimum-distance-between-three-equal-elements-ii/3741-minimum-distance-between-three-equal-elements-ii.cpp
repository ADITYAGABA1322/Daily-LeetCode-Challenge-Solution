class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() , res = INT_MAX;
        unordered_map<int , vector<int>> mp;
        for(int k=0; k<n; k++){
            mp[nums[k]].push_back(k);
            if(mp[nums[k]].size() >=3 ){
                vector<int> &vec = mp[nums[k]];
                int sz = vec.size();
                int i = vec[sz-3];
                res = min(res , 2*(k-i));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};