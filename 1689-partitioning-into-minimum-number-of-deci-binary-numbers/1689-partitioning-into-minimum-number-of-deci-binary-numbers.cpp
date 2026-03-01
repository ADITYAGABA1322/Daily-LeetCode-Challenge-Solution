class Solution {
public:
    int minPartitions(string n) {
        int maxD = 0;
        for(auto c:n){
            maxD = max(maxD , c-'0');
            if(maxD == 9) return 9;
        }
        return maxD;
    }
};