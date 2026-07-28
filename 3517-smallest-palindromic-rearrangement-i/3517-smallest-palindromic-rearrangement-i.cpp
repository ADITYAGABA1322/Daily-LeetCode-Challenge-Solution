class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26 , 0);
        for(int i=0; i<n; i++) freq[s[i]- 'a']++;
        string first = "" , mid = "";
        for(int i=0; i<26; i++){
            if(freq[i] % 2 != 0) mid = string(1 , i +'a');
            for(int j=0; j<freq[i]/2; j++){
                first += (i+'a');
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        return first + mid + second;
    }
};