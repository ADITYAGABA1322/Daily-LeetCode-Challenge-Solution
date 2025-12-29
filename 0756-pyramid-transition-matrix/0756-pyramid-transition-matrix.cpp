class Solution {
public:
    unordered_map<string , bool> memo;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string , vector<char>> mp;
        for(auto pattern : allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }
        return solve(bottom , 0 , mp ,  "");
    }
    bool solve(string curr , int idx , unordered_map<string , vector<char>>& mp , string above){
        if(curr.length() == 1) return true;
        if(idx == curr.length()-1) return solve(above , 0 , mp , "");
        string key = curr + "_" + to_string(idx) + "_" + above;
        if(memo.count(key)) return memo[key];
        string pair = curr.substr(idx , 2);
        if(mp.find(pair) == mp.end()) return memo[key] = false;
        for(auto c : mp[pair]){
            above.push_back(c);
            if(solve(curr , idx+1 , mp , above) == true) return memo[key] = true;
            above.pop_back();
        }
        return memo[key]  = false;
    }
};