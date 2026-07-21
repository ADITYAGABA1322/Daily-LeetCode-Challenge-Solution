class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activeCnt = count(begin(s), end(s) , '1');
        vector<int> inActiveBlocks;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i < n && s[i] == '0') i++;
                inActiveBlocks.push_back(i-start);
            } else i++;
        }

        int maxPairSum= 0;
        for(int i=1; i<inActiveBlocks.size(); i++){
            maxPairSum = max(maxPairSum ,inActiveBlocks[i] + inActiveBlocks[i-1]);
        }
        return maxPairSum+activeCnt;
    }
};