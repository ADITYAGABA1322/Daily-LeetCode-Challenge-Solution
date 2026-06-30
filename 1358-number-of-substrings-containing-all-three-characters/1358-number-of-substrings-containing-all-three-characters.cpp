class Solution {
public:
    int numberOfSubstrings(string s) {
        // now we want to find the sub strings containg al 3 chars ok we means we need to find usbstrs using sliding window means using 2 pointer and  ahsh tbale to freq in each substr we maintin only 1 atleast a bc in sub str we iterate through a str and fund the freq first and then use sliding window to ierate and fund the substr contain these things or not 
        int n = s.size() , i = 0;
        vector<int> cnt(3 , 0);
        int res = 0;
        for(int j = 0; j<n; j++){
            cnt[s[j] - 'a']++;
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                res += n - j;
                cnt[s[i] - 'a']--;
                i++;
            }
        }
        return res;
    }
};