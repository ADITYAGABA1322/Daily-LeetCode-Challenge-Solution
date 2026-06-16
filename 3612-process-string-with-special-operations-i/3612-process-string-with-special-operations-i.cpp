class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto c: s){
            if(c == '*'){
                if(res.size() > 0) res.pop_back();
            } else if (c == '#') res += res;
            else if(c == '%') reverse(res.begin(), res.end());
            else res+= c;
        }
        return res;
    }
};