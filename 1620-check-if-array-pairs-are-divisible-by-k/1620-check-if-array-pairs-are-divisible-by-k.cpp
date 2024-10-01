class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto a : arr) mp[(a%k + k) % k]++;
        for(auto a : arr){
            int rem = (a%k+ k) % k;
            if(rem == 0){
                if(mp[rem] % 2 == 1) return false;
            }
            else if(mp[rem] != mp[k-rem]) return false;
            
        }
        return true;
    }
};