class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // by going to the question and analyze acc to constraints which is really big 10^5 if i go with brute it goes TLE but what is brute force for this lets discuss that we given string perfrom op t times ok but hwat is that op if i say use the 26 string map or freq vector and iterate loop do one thing replace that string char to + 1 more times so that next char comes ok s[i++] or s[i]++ and check that if z is their make it to ab just take that edge case perfrom this operation t times ok
      //  int MOD = 1e9+7;
        // for(int i=0; i<t; i++){
        //     string transformed = "";
        //     for(auto c : s){
        //         if(c == 'z') transformed += "ab";
        //         else transformed += (char)(c+1);
        //     }
        //     s = transformed;
        // }
        // return s.size() % MOD;
        // TLE better appraoch
//         This approach works because we recognize that:

// We don't care about the actual characters in the string, only how many of each we have
// The transformation rules are consistent - same input always produces same output
// We can track the "population growth" of each character type mathematically
// This is a perfect example of dynamic programming where we're tracking states (character frequencies) rather than generating all possibilities - exactly what you suggested with keeping the states and avoiding regenerating the string each time!
        const int MOD = 1e9+7;
        vector<long long> freq(26 , 0);
        for(auto c : s) freq[c-'a']++;
        for(int i=0; i<t; i++){
            vector<long long> newF(26 , 0);
            for(int j=0; j<26; j++){
                if(j == 25){
                    newF[0] = (newF[0] + freq[j]) % MOD; // a
                    newF[1] = (newF[1] + freq[j]) % MOD; // b
                }else{
                    newF[j+1] = (newF[j+1] + freq[j]) % MOD;
                }
            }
            freq = newF; 
        }
        long long totalLen = 0;
        for(auto cnt : freq){
            totalLen = (totalLen + cnt) % MOD;
        }
       return totalLen;
    }
};