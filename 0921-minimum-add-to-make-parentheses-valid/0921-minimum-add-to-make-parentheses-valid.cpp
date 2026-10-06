class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 , close = 0;
        for(auto c: s){
            if(c == '(') open++;
            else if(c == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        return open + close;
    }
};