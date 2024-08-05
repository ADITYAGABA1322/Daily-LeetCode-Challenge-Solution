class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> mp;
        for(auto a : arr) mp[a]++;
        for(auto a : arr){
            if(mp[a] == 1){
                k--;
                if(k == 0) return a;
            }
        }
        return "";
    }
};