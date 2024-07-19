class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> res;
        // unordered_map<string , vector<string>> mp;
        // for(string s : strs){
        //     string temp = s;
        //     sort(temp.begin() , temp.end());
        //     mp[temp].push_back(s);
        // }
        // for(auto m : mp) res.push_back(m.second);
        // return res;
        vector<vector<string>> res;
        unordered_map<string , vector<string>> mp;
        for(auto s1 : strs){
            string s = s1;
            sort(s.begin() , s.end());
            mp[s].push_back(s1);
        }
        for(auto it : mp) res.push_back(it.second);
        return res;
    }
};