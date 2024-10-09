// simple check cha riubn sring if its ( this count it  and this ) count it and check () count make it valid rest o then we need to make it valkid ok 

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 , close = 0;
        for(char ch : s){
            if(ch == '(') open++;
            else if(ch == ')'){
                if(open > 0) open --;
                else close++; 
            }
        }
        return open + close;
    }
};