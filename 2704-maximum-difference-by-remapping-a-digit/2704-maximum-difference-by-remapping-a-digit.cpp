class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num) , large = to_string(num) , small = to_string(num);
        char dl = -1 , ds = -1;
        for(int i=0; i<s.size(); i++){
            if(dl == -1 && s[i] != '9'){
                dl = s[i];
                large[i] = '9'; 
            }
            else{
                large[i] = (s[i] == dl) ? '9' : s[i];
            }
            if(ds == -1 && s[i] != '0'){
                ds = s[i];
                small[i] = '0';
            }
            else{
                small[i] = (s[i] == ds) ? '0' : s[i];
            }
        }
        return stoi(large) - stoi(small);
    }
};