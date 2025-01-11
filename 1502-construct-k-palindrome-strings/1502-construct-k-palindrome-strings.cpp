class Solution {
public:
    bool canConstruct(string s, int k) {
        // given s and an k return truw use all char in s to constrcu k palindorme  so waht si the simple apporoach frsit chekc if string constrcut palindrome if ues count if its  qual to k or greater than return true else false for plaindrome check we use manacher if not simpler isPalindrome and hash table to check it ok  fuction to check substrings and cnt it if greater than k return it we check only odd count ok not need to check palindrome ok
        if(s.size() < k) return false;
        vector<int> f(26 , 0);
        int oddCnt  = 0;
        for(auto c : s) f[c-'a']++;
        for(auto cnt : f){
            if(cnt % 2 != 0) oddCnt++;
        }
        return oddCnt <= k;
    }
};