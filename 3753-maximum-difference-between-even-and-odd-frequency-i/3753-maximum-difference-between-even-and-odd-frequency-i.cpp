class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char , int> mp;
        int maxOdd = INT_MIN , minEven = INT_MAX;
        for(auto c : s) mp[c]++;
        for(auto it : mp){
                if(it.second % 2 == 1) maxOdd = max(maxOdd , it.second);
                if(it.second % 2 ==  0 && it.second > 0) minEven = min(minEven , it.second);
            
        }
         return maxOdd - minEven;
    }
};