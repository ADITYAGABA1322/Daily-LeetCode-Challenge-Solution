class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int , int>> numWithIndex;
        int n = nums.size();
        for(int i=0; i<n; i++){
            numWithIndex.push_back({nums[i] , i});
        }
        sort(numWithIndex.begin(), numWithIndex.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });
        vector<pair<int , int>> largest(numWithIndex.begin() , numWithIndex.begin() + k);
        sort(largest.begin() , largest.end() , [](const pair<int , int>&a , const pair<int , int>&b){
            return a.second < b.second;
        });

        vector<int> res;
        for(auto l : largest) res.push_back(l.first);
        return res;
    }
};