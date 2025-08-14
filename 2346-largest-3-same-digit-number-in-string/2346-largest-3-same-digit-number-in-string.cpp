class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for(int i=0; i<num.size(); i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string curr = num.substr(i,3);
                if(curr > res) res = curr;
            }
        }
        return res;
    }
};