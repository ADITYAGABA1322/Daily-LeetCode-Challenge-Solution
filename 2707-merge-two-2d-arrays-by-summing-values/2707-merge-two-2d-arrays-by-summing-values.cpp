class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int , int> mp;
        for(auto n1 : nums1) mp[n1[0]]+=n1[1];
        for(auto n2 : nums2) mp[n2[0]]+=n2[1];
        vector<vector<int>> res;
        for(auto entry : mp){
            res.push_back({entry.first , entry.second});
        }
        sort(res.begin() ,res.end() , [](const vector<int>& a , vector<int>& b){
            return a[0] < b[0];
        });
        return res;
    }
};