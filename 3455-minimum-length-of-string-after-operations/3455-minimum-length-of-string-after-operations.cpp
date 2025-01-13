class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() , del = 0;
        unordered_map<char , int> mp;
        for(auto c : s) mp[c]++;
        for(auto it : mp){
            del += (it.second%2) ? it.second - 1 : it.second - 2;
        } 
        return n - del;    
    }
};