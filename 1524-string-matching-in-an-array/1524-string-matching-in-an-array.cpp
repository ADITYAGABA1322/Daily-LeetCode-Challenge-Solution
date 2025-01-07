class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // using kmp 
        vector<string> res;
        int n = words.size();
        auto isSubStr = [](string &text , string& pattern){
            int m = pattern.size() , n = text.size();
            if(m == 0) return true;
            if (n == 0) return false;
            vector<int> lps(m , 0);
            int i = 1;
            int len = 0;
            while(i<m){
                if(pattern[i] == pattern[len]){
                   len++;
                   lps[i] = len;
                   i++; 
                }
                else{
                    if(len != 0){
                        len = lps[len-1];
                    }else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            i = 0;
            int j = 0;
            while(i<n){
                if(pattern[j] == text[i]){
                    i++;
                    j++;
                }
                if(j == m){
                    return true;
                }else if (i < n && pattern[j] != text[i]){
                    if(j != 0){
                    j = lps[j-1];
                    }
                 else{
                    i++;
                }
                }
            }
                   return false;
        };
 
    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && isSubStr(words[j] , words[i])){
                res.push_back(words[i]);
                break;
            }
        }
    }
    return res;
       
    }
};