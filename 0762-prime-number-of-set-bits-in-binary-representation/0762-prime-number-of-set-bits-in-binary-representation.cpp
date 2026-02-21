class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> set = {2 , 3 , 5 , 7 , 11 , 13, 17 , 19};
        int cnt = 0;
        for(int i=left; i<=right; i++){
            int bits = __builtin_popcount(i);
            if(set.count(bits)){
                cnt+=1;
            }
        }
        return cnt;
    }
};