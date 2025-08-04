class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() , i=0 , j=0 , res = 0;
        unordered_map<int , int> mp;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        } 
        return res;
    }
};