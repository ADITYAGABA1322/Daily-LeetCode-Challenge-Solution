class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // words 0 idx array ok 2d array int queries each queries[i] = [li , ri] use to find no of strs rnage li to ri both inc of words start and end  with a vowel simple take query step by step and acrrdin to srat and end index we find whoch is satrt and end wiht vowel and cnt that string ok in ans same prcedure we go it just optimized i think  for queries prefix sum is best in that case segment tree dont wokr but prefx sum how we perfomr query wise the prefix sum adjested accrding to that find the is vowl mean starta dn with vowel add to ans ans ok 
        int n = words.size();
        vector<int> pre(n+1 , 0);
        auto isVowel = [](string &s){
            char first = tolower(s.front());
            char last = tolower(s.back());
            return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
                   (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u');
        };
        for(int i=0; i<n; i++) pre[i+1] =  pre[i] + (isVowel(words[i]) ? 1 : 0);
        vector<int> res;
        for(auto q : queries){
            int li = q[0] , ri = q[1];
            res.push_back(pre[ri+1] - pre[li]);
        } 
        return res;
    }
};