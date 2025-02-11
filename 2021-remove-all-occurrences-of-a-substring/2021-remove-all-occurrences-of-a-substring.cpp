class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = part.size();
        for(auto c : s){
            res.push_back(c);
            if(res.size() >= n && res.substr(res.size() - n) == part){
                res.erase(res.size() - n , n);
            }
        }
        return res;
    }
};