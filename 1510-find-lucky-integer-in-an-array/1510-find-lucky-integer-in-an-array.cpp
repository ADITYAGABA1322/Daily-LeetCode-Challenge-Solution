class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int , int> mp;
        int maxL = -1;
        for(auto a : arr) mp[a]++;
        for(auto [num , freq] : mp){
            if(num == freq){
                maxL = max(maxL ,  num);
            }
        }
        return maxL;
    }
};