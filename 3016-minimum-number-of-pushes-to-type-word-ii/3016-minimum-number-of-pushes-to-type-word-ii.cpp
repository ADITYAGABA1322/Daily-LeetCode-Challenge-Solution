class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26 , 0);
        for(auto c: word) freq[c - 'a']++;
        sort(freq.begin() , freq.end() , greater<int>());
        int ans = 0;
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                ans += freq[i] * (1+i/8);
            }
        }
        return ans;
    }
};
