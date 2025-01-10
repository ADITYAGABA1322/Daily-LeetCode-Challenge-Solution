class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        // given 2 string array w1 and w2 ok str b subset of str a if every letter b occurs in a including multiplicity  wrr is a subset of warrior but not of world ok A string a from words1 is universal if for every string b in words2, b is a subset of a. return an arr ok what we do like the problem talks about we return arr simple just using the bsubset ofa u know how subset we find using dp or we use the bactracka ppraoch also and if nothing wokrs we use hahs map somple we go with unordered map fomr workds 1 and accrding to wrokds 2 we check how much much freq in every if we find multiple we return it 
    // Approach simple 
    // 1.) using map declare unordered_map and iterate thorugh using auto w1 : words and cnt freq ok mp.
    // 2.) by iterate thorugh w1 by it.second find sibset form words2 ok and we check max freq means it.second means multiple time and we check taht and for return in arr we need create vector<string> res ok and push back there ok and by check subset ok 

    vector<int> maxF(26 , 0);
    for(auto w : w2){
        vector<int> f = cnt(w);
        for(int i=0; i<26; i++) maxF[i] = max(maxF[i] , f[i]);
    }
    vector<string> res;
    for(auto w : w1){
        vector<int> f = cnt(w);
        if(isUniversal(f , maxF)) res.push_back(w);
    }
    return res;
    }
    private:
    vector<int> cnt(string w){
        vector<int> freq(26 , 0);
        for(auto c : w) freq[c-'a']++;
        return freq;
    }
    bool isUniversal(vector<int>&f , vector<int>& maxF){
        for(int i=0; i<26; i++){
            if(f[i] < maxF[i]) return false;
        }
        return true;
    }
};