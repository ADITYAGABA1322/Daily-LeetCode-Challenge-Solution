class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // construct a new str with repeat limit ok  and we given s and int repeat limit use char of s no letter appares more than repeat limit ok got it and u do not have to use all char from s ok  retrun lexo  largest rrepat possible ok now appraoch for this start with 2 pointer here on pointer check repeat limit and another check string and create new str in lexo order ok abd use map or heap also there
        vector<int> freq(26 , 0);
        for(auto c : s) freq[c - 'a']++;
        priority_queue<pair<char , int>> pq;
        for(int i=0; i<26; i++){
            if(freq[i] > 0) pq.push({(char)('a' + i) , freq[i]});
        }
        string res;
        while(!pq.empty()){
            auto[c1 , f1] = pq.top();
            pq.pop();
            int minCnt = min(f1  , repeatLimit);
            res.append(minCnt ,c1);
            f1 -= minCnt;
            if(f1>0){
                if(pq.empty()) break; 
            auto [c2 , f2] = pq.top();
            pq.pop();
            res.push_back(c2);
            f2--;
            if(f2 > 0) { 
                pq.push({c2 , f2});
            }
            pq.push({c1 , f1});
            }
        }
        return res;
    }
};