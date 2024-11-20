class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3 , 0);
        for(auto c:s) cnt[c-'a']++;
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k ) return -1;
        int n = s.size();
        int maxLen = 0;
        int left = 0;
        vector<int> mp(3 , 0);
        for(int right = 0; right <n; right++){
            mp[s[right]-'a']++;
            while(mp[0] > cnt[0] - k || mp[1] > cnt[1] - k || mp[2] > cnt[2] - k){
                mp[s[left] - 'a']--;
                left++;
            } 
            maxLen = max(maxLen , right-left+1);
        }
        return n-maxLen;;
    }
};