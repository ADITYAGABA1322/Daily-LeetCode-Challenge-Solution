class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        // just simple approach for this lets tart with its about sibseq u knnow evry sub take it  or not just simple like that we nned to check that if the string which is comes k times or not n sub seq if yea jsut return longest lexo sub seq but how if we cnt freq first then check that work k times or not k * subseq or freq as you know after we process to check lexo string and return it let see greedy approach first cnt freq and then tkae it or not acc to k times after we return longest means max and i lexo means a to z order way 
        int n = s.size();
        vector<int> freq(26 , 0);
        for(auto c : s) freq[c-'a']++;
        string validChar = "";
        for(int i=0; i<26; i++){
            if(freq[i] >= k) validChar += ('a'+i);
        }
        vector<string> candidates = {""};
        string result = "";
        while(!candidates.empty()){
            vector<string> next;
            for(string& candidate: candidates){
                for(auto c: validChar){
                    string newCandidate = candidate + c;
                    if(checkSubseq(s , newCandidate , k)){
                        next.push_back(newCandidate);
                        result = newCandidate;
                    }
                }
            }
            if(next.empty()) break;
            candidates = next;
        }
        return result;
    }

private:
    bool checkSubseq(string& s , string& sub , int k){
        int count = 0;
        int i = 0;
        while(i<s.length() && count < k){
            int j = 0;
            while(i<s.length() && j < sub.length()){
                if(s[i] == sub[j]) j++;
                i++;
            }
            if(j == sub.length()) count++;
            else break;
        }
        return count>=k;
    }
};