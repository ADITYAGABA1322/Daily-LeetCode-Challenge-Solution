class Solution {
public:
    // TLE -> O(N^2)
    // bool check(vector<int> freq){
    //     int common = 0;
    //     for(int i=0; i<26; i++){
    //         if(freq[i] == 0) continue;
    //         if(common == 0) common = freq[i];
    //         else if(common != freq[i]) return false;
    //     } 
    //     return true;
    // }
     int longestBalanced(string s) {
    //     int n = s.size();
    //     int maxLen = 0;
    //     for(int i=0; i<n; i++){
    //         vector<int> freq(26 , 0);
    //         for(int j=i; j<n; j++){
    //             freq[s[j] - 'a']++;
    //             if(check(freq)){
    //                 maxLen = max(maxLen , j - i + 1);
    //             }
    //         }
    //     }
    //     return maxLen;

    int n = s.size();
    int maxLen = 0;
    int cnt = 1;

    // case 1: if aaaa or bbbb which is bigger
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            maxLen = max(maxLen , cnt);
            cnt = 1;
        }
    }

    maxLen = max(maxLen , cnt);
    
    // case 2 (aabbbc) (aabcc)
    maxLen = max(maxLen , helper(s , 'a' , 'b'));
    maxLen = max(maxLen , helper(s , 'b' , 'c'));
    maxLen = max(maxLen , helper(s , 'a' , 'c'));


    // case 3 (aabbccabc)
    int cnt1 = 0 ,cnt2 = 0 , cnt3 = 0;
    unordered_map<string , int> diffMap;

    for(int i=0; i<n; i++){
        if(s[i] == 'a') cnt1++;
        if(s[i] == 'b') cnt2++;
        if(s[i] == 'c') cnt3++;

        if(cnt1 == cnt2 && cnt1 == cnt3){
            maxLen = max(maxLen , cnt1+cnt2+cnt3);
        }

        int diff12 = cnt1 - cnt2;
        int diff13 = cnt1 - cnt3;

        string key = to_string(diff12) + "_" + to_string(diff13);
        if(diffMap.count(key)){
            maxLen = max(maxLen , i - diffMap[key]);
        } else{
            diffMap[key] = i;
        }
    }
    return maxLen;
    }

    int helper(string& s, char ch1, char ch2) {  // char instead of int
    unordered_map<int, int> diffMap;
    int maxLen = 0, n = s.size();
    int cnt1 = 0, cnt2 = 0;
    
    diffMap[0] = -1;  // Handle edge case
    
    for(int i = 0; i < n; i++) {
        if(s[i] != ch1 && s[i] != ch2) {  // ✅ Fixed: s[i] not s[2]
            diffMap.clear();
            diffMap[0] = i;
            cnt1 = cnt2 = 0;
            continue;
        }
        
        if(s[i] == ch1) cnt1++;
        if(s[i] == ch2) cnt2++;
        
        int diff = cnt1 - cnt2;
        if(diffMap.count(diff)) {
            maxLen = max(maxLen, i - diffMap[diff]);
        } else {
            diffMap[diff] = i;
        }
    }
    return maxLen;
}
};