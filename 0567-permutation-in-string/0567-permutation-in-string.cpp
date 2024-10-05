class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26);
        vector<int> v2(26);
        for(int i=0; i<s1.length(); i++){
            v1[s1[i] - 'a']++;
        }
        for(int i=0; i<s2.length(); i++){
            v2[s2[i]-'a']++;
            if(i>=s1.size()){
                v2[s2[i-s1.size()]-'a']--;
            }
            if(v1 == v2) return true;
        }
        return false;
        
    }
};
