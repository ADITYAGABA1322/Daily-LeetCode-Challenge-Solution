class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // in given arr = [3,3,3,3,3,1,3] you see one thing the idces first we give 3 comes in index = [0,1,2,3,4,6] ,  and 1 comes in index = [5] ok lets go with first 3 total len of the array which these indices have 6/3 = 2 ok [0,1,2] and [3,4,6] for 1 its 1/1 = 1 so [5] we retun those arr ok. 
        int n = groupSizes.size();
        vector<vector<int>> res;
        unordered_map<int , vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[groupSizes[i]].push_back(i);
             if(mp[groupSizes[i]].size() == groupSizes[i]){
                res.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
             }
        }
        return res;
    }
};