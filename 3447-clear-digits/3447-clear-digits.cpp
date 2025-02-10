class Solution {
public:
    string clearDigits(string s) {
        vector<char> res;
        for(char c : s){
            if(c >= '0' && c<='9' &&  res.size() > 0) res.pop_back();
            else res.push_back(c);
        }
        return string(res.begin() , res.end());
    }
};