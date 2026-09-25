class Solution {
public:
set<string> solve(string expr) {
    set<string> res;
    int depth = 0;
    int i = 0;
    // CASE 1: find top level comma
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '{') depth++;
        else if (expr[i] == '}') depth--;
        else if (expr[i] == ',' && depth == 0) {
            set<string> leftSet = solve(expr.substr(0 , i));
            set<string> rightSet = solve(expr.substr(i+1));
            res.insert(leftSet.begin(), leftSet.end());
            res.insert(rightSet.begin(), rightSet.end());
            return res;
        }
    }
    
    // CASE 2 & 3: cartesian product
    set<string> curr = {""};
    depth = 0;
    while (i < expr.size()) {
        if (expr[i] == '{') {
            int j = i;
            while(j < expr.size()){
                if(expr[j] == '{') depth++;
                else if(expr[j] == '}') depth--;
                if(depth == 0) break;
                 j++;
            }
            set<string> inner = solve(expr.substr(i+1 , j-i-1));
            set<string> newSet;
            for(auto s : curr){
                for(auto t: inner){
                    newSet.insert(s+t);
                }
            }
            curr = newSet;
            i = j+1;
        } else {
            // single letter case
            // you already wrote this
            set<string> newSet;
            for(auto s: curr){
                newSet.insert(s + expr[i]);
            }
            curr = newSet;
            i++;
        }
    }
    
    return curr;
};
    vector<string> braceExpansionII(string expression) {
        set<string> res = solve(expression);
        vector<string> ans = vector<string>(res.begin() , res.end());
        return ans;
    }
};