class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};
        int n = s1.size();
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else{
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i=0; i<26; i++){
            if(even[i]!=0 || odd[i] != 0) return false;
        }
        return true;
    }
};