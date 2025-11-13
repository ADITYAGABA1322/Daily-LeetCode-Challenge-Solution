class Solution {
public:
        int maxOperations(string s) {
        int res=0,on=0;
        bool check=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                on++;
                check=true;
            }
            else{
                if(check) res+=on;
                check=false;
            }
        }
        return res;
    }
    
};