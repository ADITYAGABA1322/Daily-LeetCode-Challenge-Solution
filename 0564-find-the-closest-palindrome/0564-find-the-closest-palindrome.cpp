class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        if(len == 1) return to_string(stoi(n)-1);
        vector<long>  candidates;
        long num = stol(n);
        candidates.push_back((long)pow(10 , len -1) -1);
        candidates.push_back((long)pow(10 , len) + 1);
        long pre = stol(n.substr( 0 , (len+1) / 2));
        for(int i=-1; i<=1; i++){
            string p = to_string(pre + i);
            string candidate = p + string(p.rbegin() + (len & 1), p.rend());
            candidates.push_back(stol(candidate));
        }
        long close = -1;
        for(auto candidate : candidates){
            if(candidate != num){
                if(close == -1 || abs(candidate - num) < abs(close - num) || abs(candidate - num) == abs(close - num)  && candidate < close){
                    close = candidate;
                }
            }
        }
        return to_string(close);
    }
};